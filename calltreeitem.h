#ifndef CALLTREEITEM_H
#define CALLTREEITEM_H

#include "callcodeobject.h"

#include <QStandardItem>

class CallTreeItem : public QStandardItem
{
public:
    CallTreeItem();

    void setData(CallCodeObject *);

    CallCodeObject* data();

private:
    CallCodeObject *m_data;
};

#endif // CALLTREEITEM_H
