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

#include "disassembledialog.h"
#include "ui_disassembledialog.h"
#include <QFileDialog>

DisassembleDialog::DisassembleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisassembleDialog)
{
    ui->setupUi(this);
}

DisassembleDialog::~DisassembleDialog()
{
    delete ui;
}

void DisassembleDialog::on_dispelPushButton_clicked()
{
    dispelExe = QFileDialog::getOpenFileName(this,
                                              tr("Pick dispel executable"), QString("D:/Project"), tr("Dispel.exe (*.exe)"));
    ui->dispelLineEdit->setText(dispelExe);
}

void DisassembleDialog::runDispell()
{

}

void DisassembleDialog::on_romPushButton_clicked()
{
    romFile = QFileDialog::getOpenFileName(this,
                                              tr("Choose the SNES rom"), QString("D:/Emulation"), tr("SNES Rom (*.sfc, *smc)"));
    ui->romPathLineEdit->setText(romFile);
}
