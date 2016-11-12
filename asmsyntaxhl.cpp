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

#include "asmsyntaxhl.h"
#include <QRegExp>

ASMSyntaxHL::ASMSyntaxHL(QObject *parent) : QSyntaxHighlighter(parent)
{
    bankFormat.setForeground(Qt::darkGray);
    addrFormat.setForeground(Qt::darkRed);
    hexValueFormat.setForeground(Qt::blue);
    instrFormat.setForeground(Qt::darkGreen);
    argsFormat.setForeground(Qt::darkMagenta);
}


// C0/9173:	BEA596  	ldx $96A5,Y
// C0/9176:	B92797  	lda $9727,Y
// C0/9179:	9D2797  	sta $9727,X

void ASMSyntaxHL::highlightBlock(const QString &text)
{
    setFormat(0, 2, bankFormat);
    setFormat(3, 4, addrFormat);
    //QRegExp hexValReg("[^ ]+");
    //hexValReg.indexIn(text.mid(9));
    //setFormat(9, 9 + hexValReg.matchedLength(), hexValueFormat);
    setFormat(9, 9 + 8, hexValueFormat);
    setFormat(9 + 8 + 1, 3, instrFormat);
    setFormat(9 + 8 + 1 + 3 + 1, text.length() -  9 + 8 + 1 + 3 + 1, argsFormat);
}
