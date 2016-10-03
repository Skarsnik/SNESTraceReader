#include "calltreeitem.h"

CallTreeItem::CallTreeItem()
{
}

void CallTreeItem::setData(CallCodeObject *i)
{
    m_data = i;
    setText(i->start_addr + " - " + i->stop_addr + " {" + QString::number(i->start_line) + "," + QString::number(i->stop_line) + "}");
}

CallCodeObject* CallTreeItem::data() {
    return m_data;
}
