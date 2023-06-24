// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "mainwindow.h"
#include "widget/filechoosearea.h"
#include "widget/pipelinearea.h"
#include "widget/logarea.h"
#include "widget/mediainfoarea.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , fileChooseArea(new FileChooseArea)
    , pipelineArea(new PipelineArea)
    , logArea(new LogArea)
    , mediaInfoArea(new MediaInfoArea)
{
    initUI();

    pipelineArea->setFileListFuction([this](){ return fileChooseArea->fileList(); });

    connect(fileChooseArea, &FileChooseArea::selectFileChanged, mediaInfoArea, &MediaInfoArea::setInfo);
    connect(pipelineArea, &PipelineArea::finished, this, &MainWindow::onPipelineFinished);
}

void MainWindow::initUI()
{
    auto pannelLayer = new QVBoxLayout;
    pannelLayer->addWidget(fileChooseArea);
    pannelLayer->addWidget(pipelineArea);
    pannelLayer->addWidget(logArea);

    auto allLayer = new QHBoxLayout;
    allLayer->addLayout(pannelLayer, 3);
    allLayer->addWidget(mediaInfoArea, 1);

    auto center = new QWidget;
    center->setLayout(allLayer);
    setCentralWidget(center);
    resize(1280, 720);
    setWindowTitle(tr("呆呆视频工具箱"));
}

void MainWindow::onPipelineFinished(bool isAllRight)
{
    if(isAllRight)
    {
        logArea->setLogInfo(tr("已顺利完成本轮处理"));
    }
}
