// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QWidget>

class QProgressBar;
class QTextEdit;

class LogArea : public QWidget
{
    Q_OBJECT
public:
    explicit LogArea(QWidget *parent = nullptr);

    void setLogInfo(const QString &info);
    void setCurrentProcess(int now, int all);
    void setAllProcess(int now, int all);

signals:

private:
    QProgressBar *currentBar;
    QProgressBar *allBar;
    QTextEdit *logBox;
};
