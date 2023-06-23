// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "pipelinearea.h"

#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>

PipelineArea::PipelineArea(QWidget *parent)
    : QWidget(parent)
    , useLosslessCompressionBox(new QCheckBox(tr("自动无损压制")))
    , targetBpsEdit(new QLineEdit)
    , outputEdit(new QLineEdit)
{
    auto chooseOutputButton = new QPushButton(tr("选择路径"));
    auto startButton = new QPushButton(tr("执行转换"));

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
