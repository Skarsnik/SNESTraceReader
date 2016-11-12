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

#include "disassemblywindow.h"
#include "ui_disassemblywindow.h"
#include "asmsyntaxhl.h"

DisassemblyWindow::DisassemblyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisassemblyWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);

    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    ASMSyntaxHL* syntaxHL = new ASMSyntaxHL(ui->ASMPlainTextEdit->document());
    syntaxHL->setDocument(ui->ASMPlainTextEdit->document());

    ui->ASMPlainTextEdit->setFont(font);
}

DisassemblyWindow::~DisassemblyWindow()
{
    delete ui;
}

void DisassemblyWindow::setDisassembly(QString &text)
{
    ui->ASMPlainTextEdit->clear();
    ui->ASMPlainTextEdit->appendPlainText(text);

    QTextCursor cur(ui->ASMPlainTextEdit->document());
    cur.movePosition(QTextCursor::Start);
    ui->ASMPlainTextEdit->setTextCursor(cur);

}

void DisassemblyWindow::on_pushButton_2_clicked()
{
    close();
}
