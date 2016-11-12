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

#ifndef TRACEHIGHLIGHTER_H
#define TRACEHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class TraceHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit TraceHighlighter(QObject *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

private:
    struct HighlightingRule
        {
            QRegExp pattern;
            QTextCharFormat format;
        };
    QVector<HighlightingRule> highlightingRules;

    QStringList     branchInstruction;

    //8083f1 ldy $0145,x   [8002cd] A:0000 X:0188 Y:0b44 S:1fe2 D:0000 DB:80 nvMxdizc V:230

    QTextCharFormat instructionAddrFormat;

    QTextCharFormat normalInstructionFormat;
    QTextCharFormat branchInstructionFormat;
    QTextCharFormat instructionArgFormat;
    QTextCharFormat instructionValueFormat;

    QTextCharFormat registerNameFormat;
    QTextCharFormat registerValueFormat;

    //QTextCharFormat
};

#endif // TRACEHIGHLIGHTER_H
