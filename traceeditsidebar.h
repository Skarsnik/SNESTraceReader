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

#ifndef TRACEEDITSIDEBAR_H
#define TRACEEDITSIDEBAR_H

#include <QWidget>
#include "snestracetextedit.h"

class TraceEditSidebar : public QWidget
{
    Q_OBJECT
public:
    explicit TraceEditSidebar(SnesTraceTextEdit* parent = 0);


signals:

public slots:


protected:
    void    paintEvent(QPaintEvent *event);
    QSize   sizeHint() const;

private:
    SnesTraceTextEdit* m_traceEdit;
};

#endif // TRACEEDITSIDEBAR_H
