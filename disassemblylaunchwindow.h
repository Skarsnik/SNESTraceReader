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

#ifndef DISASSEMBLYLAUNCHWINDOW_H
#define DISASSEMBLYLAUNCHWINDOW_H

#include <QProcess>
#include <QSettings>
#include <QWidget>
#include "disassemblywindow.h"

namespace Ui {
class DisassemblyLaunchWindow;
}

class DisassemblyLaunchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisassemblyLaunchWindow(QWidget *parent = 0);
    ~DisassemblyLaunchWindow();


private slots:
    void on_dispelPushButton_clicked();

    void on_romPushButton_clicked();

    void on_Process_finished(int exitCode, QProcess::ExitStatus exitStatus);

    void on_pushButton_clicked();

private:
    Ui::DisassemblyLaunchWindow *ui;

    QProcess*           dispelProcess;
    DisassemblyWindow*  dissWindow;

    QString dispelExe;
    QString romFile;
    void closeEvent(QCloseEvent *);

    QSettings* m_settings;

    bool    loROM;
    bool    hiROM;
    bool    header;

    void    runDispell();
};

#endif // DISASSEMBLYLAUNCHWINDOW_H
