// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QWidget>
#include <functional>

class QCheckBox;
class QLineEdit;

class PipelineArea : public QWidget
{
    Q_OBJECT
public:
    explicit PipelineArea(QWidget *parent = nullptr);

    void setFileListFuction(const std::function<QStringList(void)> &func);

signals:
    void currentProcess(int current, int all);
    void allProcess(int current, int all);
    void finished(bool isAllRight); //true: 正常走完流程，false：用户手动退出或异常退出

private:
    void runCompression();
    void runLosslessCompression(const QStringList &fileList, const QString &outputPath);

    QCheckBox *useLosslessCompressionBox;
    QLineEdit *targetBpsEdit;
    QLineEdit *outputEdit;

    std::function<QStringList(void)> fileListFuctor;
};
