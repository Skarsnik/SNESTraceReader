#ifndef ASMSYNTAXHL_H
#define ASMSYNTAXHL_H

#include <QSyntaxHighlighter>

class ASMSyntaxHL : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit ASMSyntaxHL(QObject *parent = 0);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    QTextCharFormat bankFormat;
    QTextCharFormat addrFormat;
    QTextCharFormat hexValueFormat;
    QTextCharFormat instrFormat;
    QTextCharFormat argsFormat;
};

#endif // ASMSYNTAXHL_H
