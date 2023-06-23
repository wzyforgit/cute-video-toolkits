// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QWidget>

class QTextEdit;

class MediaInfoArea : public QWidget
{
    Q_OBJECT
public:
    explicit MediaInfoArea(QWidget *parent = nullptr);

    void setInfo(const QString &path);

signals:

private:
    QTextEdit *mediaInfoBox;
};
