// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QWidget>

class QLabel;
class QStackedWidget;
class QListView;
class QStringListModel;

class FileChooseArea : public QWidget
{
    Q_OBJECT
public:
    explicit FileChooseArea(QWidget *parent = nullptr);

signals:
    void selectFileChanged(const QString &filePath);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    void addNewFiles(const QList<QUrl> &urls);

    QLabel *dropLabel;
    QStackedWidget *centerWidget;
    QListView *fileListView;
    QStringListModel *fileListmodel;
};
