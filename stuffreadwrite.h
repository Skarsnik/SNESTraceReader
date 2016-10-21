#ifndef STUFFREADWRITE_H
#define STUFFREADWRITE_H

#include <QString>
#include <QList>

struct lineInstr {
    int lineNumber;
    QString line;
};

struct trackStuff {
    int addr;
    QList<lineInstr> where;
};

#endif // STUFFREADWRITE_H
