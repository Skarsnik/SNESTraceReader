#include "calltreeitem.h"

CallTreeItem::CallTreeItem()
{
}

void CallTreeItem::setData(CallCodeObject *i)
{
    m_data = i;
    setText(i->start_addr + " - " + i->stop_addr + " {" + QString::number(i->start_line + 1) + "," + QString::number(i->stop_line == -1 ? -1 : i->stop_line + 1) + "}");
}

CallCodeObject* CallTreeItem::data() {
    return m_data;
}
