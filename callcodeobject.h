#ifndef CALLCODEOBJECT_H
#define CALLCODEOBJECT_H

#include <QString>
#include <QList>

struct CallCodeObject {
    int         start_line;
    int         stop_line;
    QString     start_addr;
    QString     stop_addr;

    CallCodeObject* parent;
    QList<CallCodeObject*>   children;
};


#endif // CALLCODEOBJECT_H
