// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "mediainfoarea.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QTextEdit>

#include "cutevideo/lib.h"

MediaInfoArea::MediaInfoArea(QWidget *parent)
    : QWidget(parent)
    , mediaInfoBox(new QTextEdit)
{
    mediaInfoBox->setReadOnly(true);

    auto allLayer = new QHBoxLayout;
    allLayer->addWidget(mediaInfoBox);
    setLayout(allLayer);
}

void MediaInfoArea::setInfo(const QString &path)
{
    mediaInfoBox->clear();
    mediaInfoBox->insertPlainText(videoInfo(path));
}
