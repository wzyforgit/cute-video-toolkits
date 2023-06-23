// SPDX-FileCopyrightText: 2023 wzyforgit
//
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <QWidget>

class QCheckBox;
class QLineEdit;

class PipelineArea : public QWidget
{
    Q_OBJECT
public:
    explicit PipelineArea(QWidget *parent = nullptr);

signals:

private:
    QCheckBox *useLosslessCompressionBox;
    QLineEdit *targetBpsEdit;
    QLineEdit *outputEdit;
};
