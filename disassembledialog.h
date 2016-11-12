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

#ifndef DISASSEMBLEDIALOG_H
#define DISASSEMBLEDIALOG_H

#include <QDialog>

namespace Ui {
class DisassembleDialog;
}

class DisassembleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisassembleDialog(QWidget *parent = 0);
    ~DisassembleDialog();

private slots:
    void on_dispelPushButton_clicked();

    void on_romPushButton_clicked();

private:
    Ui::DisassembleDialog *ui;

    QString dispelExe;
    QString romFile;

    bool    loROM;
    bool    hiROM;
    bool    header;

    void    runDispell();
};

#endif // DISASSEMBLEDIALOG_H
