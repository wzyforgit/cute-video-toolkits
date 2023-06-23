// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "utils.h"

#include <QMimeDatabase>
#include <QMimeType>
#include <QDir>

bool isVideoFile(const QString &path)
{
    QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(path);
    auto mimeTypeName = type.name();
    return mimeTypeName.startsWith("video/");
}

static void getAllVideoFileInDir(const QDir &dir, QStringList &result)
{
    QDir root(dir);
    auto list = root.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    for (const auto &eachInfo : list) {
        if (eachInfo.isDir()) {
            getAllVideoFileInDir(eachInfo.absoluteFilePath(), result);
        } else {
            auto fileFullPath = eachInfo.absoluteFilePath();
            if(isVideoFile(fileFullPath))
            {
                result.push_back(fileFullPath);
            }
        }
    }
}

QStringList findVideoFiles(const QString &dirPath)
{
    QDir root(dirPath);
    QStringList result;
    getAllVideoFileInDir(root, result);

    return result;
}
