// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#include "lib.h"

#include <QProcess>

#include <MediaInfoDLL/MediaInfoDLL.h>

QString videoInfo(const QString &path)
{
    MediaInfoDLL::MediaInfo info;
    info.Open(path.toStdString());
    info.Option("Complete", "1");
    info.Option("Inform", "CSV");
    QString strData(info.Inform().c_str());
    return strData;
}

bool losslessCompression(const QString &filePath, const QString &outputFilePath)
{
    QProcess process;

    //demo: ffmpeg -i xxx.mp4 -y yyy.mp4
    process.start("ffmpeg", {"-i", filePath, "-y", outputFilePath});

    return process.waitForFinished(-1);
}
