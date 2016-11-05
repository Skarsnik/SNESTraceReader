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
