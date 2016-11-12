/*
 * Copyright (C) 2016 Sylvain "Skarsnik" Colinet

This software is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SIMPLETRACEWINDOW_H
#define SIMPLETRACEWINDOW_H

#include "tracehighlighter.h"

#include <QTextDocument>
#include <QWidget>
#include <QList>

namespace Ui {
class SimpleTraceWindow;
}

class SimpleTraceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTraceWindow(QWidget *parent = 0);
    ~SimpleTraceWindow();
    void    setLineNumbers(QList<uint>& lineNumbers);
    void    setText(QString text);

private:
    Ui::SimpleTraceWindow *ui;
};

#endif // SIMPLETRACEWINDOW_H
