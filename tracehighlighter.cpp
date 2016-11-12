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

#include "tracehighlighter.h"
#include <QDebug>

TraceHighlighter::TraceHighlighter(QObject *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    branchInstruction << "bne" << "beq" << "jmp" << "jsl" << "rts" << "rti" << "rtl" << "jml";


    //8083f1 ldy $0145,x   [8002cd] A:0000 X:0188 Y:0b44 S:1fe2 D:0000 DB:80 nvMxdizc V:230

    instructionAddrFormat.setForeground(Qt::darkCyan);

    normalInstructionFormat.setForeground(Qt::black);
    branchInstructionFormat.setForeground(Qt::darkRed);
    instructionArgFormat.setForeground(Qt::darkGreen);
    instructionValueFormat.setForeground(Qt::blue);

    registerNameFormat.setForeground(Qt::black);
    registerValueFormat.setForeground(Qt::darkMagenta);


    //QRegExp instructionAddrExp("^[0123456789abcdef]+");
    //QRegExp instructionExp("\\b\\w{3}\\b");
    qDebug() << "Init syntax HL";
}

void TraceHighlighter::highlightBlock(const QString &text)
{
    //qDebug() << "piko" << text;
    if (text.size() == 0)
            return;
    setFormat(0, 6, instructionAddrFormat);
    QString inst = text.mid(7,3);
    if (branchInstruction.contains(inst)) {
        setFormat(7, 3, branchInstructionFormat);
    } else {
        setFormat(7, 3, normalInstructionFormat);
    }
    QRegExp argR("[^ ]+");
    argR.indexIn(text, 10);
    QString arg = argR.cap();
    QTextCharFormat argFormat = instructionArgFormat;
    if (arg.at(0) == '#') {
       argFormat.setUnderlineStyle(QTextCharFormat::DotLine);
    }
    setFormat(11, argR.matchedLength(), argFormat);
    setFormat(22, 6, instructionValueFormat);

    setFormat(32, 4, registerValueFormat);

    QTextCharFormat XForm = registerValueFormat;
    XForm.setForeground(QColor(Qt::darkMagenta).darker());
    setFormat(39, 4, XForm);

    setFormat(46, 4, registerValueFormat);


}
