// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "pipelinearea.h"
#include "cutevideo/lib.h"

#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include <QtDebug>

PipelineArea::PipelineArea(QWidget *parent)
    : QWidget(parent)
    , useLosslessCompressionBox(new QCheckBox(tr("自动无损压制")))
    , targetBpsEdit(new QLineEdit)
    , outputEdit(new QLineEdit)
{
    auto chooseOutputButton = new QPushButton(tr("选择路径"));
    connect(chooseOutputButton, &QPushButton::clicked, [this](){
        auto dirPath = QFileDialog::getExistingDirectory();
        if(!dirPath.isEmpty())
        {
            outputEdit->setText(dirPath);
        }
    });

    auto startButton = new QPushButton(tr("执行转换"));
    startButton->setStyleSheet("background-color : red");
    connect(startButton, &QPushButton::clicked, this, &PipelineArea::runCompression);

    auto normalParamSettingLayer = new QHBoxLayout;
    normalParamSettingLayer->addWidget(useLosslessCompressionBox);
    normalParamSettingLayer->addWidget(new QLabel(tr("码率设置（kbps）：")));
    normalParamSettingLayer->addWidget(targetBpsEdit);

    auto outputAndStartLayer = new QHBoxLayout;
    outputAndStartLayer->addWidget(new QLabel(tr("输出路径：")));
    outputAndStartLayer->addWidget(outputEdit);
    outputAndStartLayer->addWidget(chooseOutputButton);
    outputAndStartLayer->addWidget(startButton);

    auto allLayer = new QVBoxLayout;
    allLayer->addLayout(normalParamSettingLayer);
    allLayer->addLayout(outputAndStartLayer);
    setLayout(allLayer);
}

void PipelineArea::setFileListFuction(const std::function<QStringList(void)> &func)
{
    fileListFuctor = func;
}

void PipelineArea::runCompression()
{
    //1.检查输出目录是否有效
    auto outputPath = outputEdit->text();
    QFileInfo info(outputPath);
    if(!info.isDir() || !info.isWritable())
    {
        QMessageBox::critical(nullptr, tr("错误"), tr("无效的输出路径"));
        return;
    }

    //2.检查是否存在需要处理的文件
    auto files = fileListFuctor();
    if(files.isEmpty())
    {
        QMessageBox::critical(nullptr, tr("错误"), tr("没有选择需要处理的文件"));
        return;
    }

    //3.根据界面选项进行处理流程
    if(!outputPath.endsWith("/"))
    {
        outputPath += "/";
    }

    if(useLosslessCompressionBox->isChecked())
    {
        runLosslessCompression(files, outputPath);
    }
}

void PipelineArea::runLosslessCompression(const QStringList &fileList, const QString &outputPath)
{
    for(auto &file : fileList)
    {
        QFileInfo infoInput(file);
        auto inputFileName = infoInput.fileName();
        auto outputName = outputPath + inputFileName;

        //解决名字冲突
        while(1)
        {
            QFileInfo infoOutput(outputName);
            if(infoOutput.exists())
            {
                auto suffix = infoOutput.suffix();
                auto fileName = infoOutput.fileName();
                auto fileNameNoSuffix = fileName.left(fileName.size() - suffix.size() - 1);
                auto newFileName = fileNameNoSuffix + "_new." + suffix;
                outputName = outputPath + newFileName;
            }
            else
            {
                break;
            }
        }

        losslessCompression(file, outputName);
    }

    emit finished(true);
}
