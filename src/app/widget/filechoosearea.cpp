// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "filechoosearea.h"
#include "utils.h"

#include <QLabel>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QListView>
#include <QStringListModel>
#include <QFileInfo>
#include <QMessageBox>
#include <QtDebug>

FileChooseArea::FileChooseArea(QWidget *parent)
    : QWidget(parent)
    , dropLabel(new QLabel(tr("将视频文件或文件夹拖放至此")))
    , centerWidget(new QStackedWidget)
    , fileListView(new QListView)
    , fileListmodel(new QStringListModel)
{
    fileListView->setModel(fileListmodel);
    connect(fileListView, &QListView::pressed, [this](const QModelIndex &index){
        auto path = fileListmodel->data(index).toString();
        if(!path.isEmpty())
        {
            emit selectFileChanged(path);
        }
    });

    centerWidget->addWidget(dropLabel);
    centerWidget->addWidget(fileListView);

    auto allLayer = new QHBoxLayout;
    allLayer->addWidget(centerWidget);
    setLayout(allLayer);

    setMouseTracking(true);
    setAcceptDrops(true);
}

void FileChooseArea::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void FileChooseArea::dropEvent(QDropEvent *event)
{
    addNewFiles(event->mimeData()->urls());
    event->accept();
}

void FileChooseArea::addNewFiles(const QList<QUrl> &urls)
{
    QStringList filePaths;
    for(auto &url : urls)
    {
        if(!url.isLocalFile())
        {
            continue;
        }
        auto path = url.toLocalFile();
        QFileInfo info(path);
        if(info.isDir())
        {
            filePaths.append(findVideoFiles(path));
        }
        else if(isVideoFile(path))
        {
            filePaths.append(path);
        }
    }

    if(filePaths.isEmpty())
    {
        QMessageBox::critical(nullptr, tr("错误"), tr("未检测到有效的视频文件"));
    }

    qDebug() << "Ready to add files: " << filePaths;

    auto oldList = fileListmodel->stringList();
    auto newList = oldList + filePaths;
    QSet<QString> pathSet(newList.begin(), newList.end());
    fileListmodel->setStringList(pathSet.values());
    centerWidget->setCurrentWidget(fileListView);
}

QStringList FileChooseArea::fileList() const
{
    return fileListmodel->stringList();
}
