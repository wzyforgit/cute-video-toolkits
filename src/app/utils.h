// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QStringList>

extern bool isVideoFile(const QString &path);
extern QStringList findVideoFiles(const QString &dirPath);
