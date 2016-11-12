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
