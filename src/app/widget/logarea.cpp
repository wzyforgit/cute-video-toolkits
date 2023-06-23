// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "logarea.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QTextEdit>

LogArea::LogArea(QWidget *parent)
    : QWidget(parent)
    , currentBar(new QProgressBar)
    , allBar(new QProgressBar)
    , logBox(new QTextEdit)
{
    auto currentBarLayer = new QHBoxLayout;
    currentBarLayer->addWidget(new QLabel(tr("当前进度：")));
    currentBarLayer->addWidget(currentBar);

    auto allBarLayer = new QHBoxLayout;
    allBarLayer->addWidget(new QLabel(tr("全局进度：")));
    allBarLayer->addWidget(allBar);

    auto allLayer = new QVBoxLayout;
    allLayer->addLayout(currentBarLayer);
    allLayer->addLayout(allBarLayer);
    allLayer->addWidget(logBox);
    setLayout(allLayer);

    setCurrentProcess(0, 1);
    setAllProcess(0, 1);
}

void LogArea::setLogInfo(const QString &info)
{
    logBox->moveCursor(QTextCursor::End);
    logBox->insertPlainText(info + "\n");
    logBox->moveCursor(QTextCursor::End);
}

void LogArea::setCurrentProcess(int now, int all)
{
    currentBar->setRange(0, all);
    currentBar->setValue(now);
}

void LogArea::setAllProcess(int now, int all)
{
    allBar->setRange(0, all);
    allBar->setValue(now);
}
