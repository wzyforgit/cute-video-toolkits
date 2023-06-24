// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QMainWindow>

class FileChooseArea;
class PipelineArea;
class LogArea;
class MediaInfoArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

private:
    void initUI();
    void onPipelineFinished(bool isAllRight);

    FileChooseArea *fileChooseArea;
    PipelineArea *pipelineArea;
    LogArea *logArea;
    MediaInfoArea *mediaInfoArea;
};
