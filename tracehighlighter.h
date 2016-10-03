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
