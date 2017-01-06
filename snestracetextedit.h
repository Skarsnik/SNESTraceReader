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
#ifndef SNESTRACETEXTEDIT_H
#define SNESTRACETEXTEDIT_H

#include <QWidget>
#include <QPlainTextEdit>
#include "tracehighlighter.h"
//#include "traceeditsidebar.h"

class SnesTraceTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    SnesTraceTextEdit(QWidget *parent = 0);

    int     sideBarAreaWidth();
    void    sideBarPaintEvent(QPaintEvent *event);
    void    resizeEvent(QResizeEvent*ev);
    void    setCursorToLine(int lineNumber);

    void setLineNumberList(const QList<uint> &value);

    void setSpecifiedLineNumber(bool value);
    void    setSearchSelection(const QTextEdit::ExtraSelection &);

private slots:
    void    updateSideBarAreaWidth(int);
    void    on_cursorPositionChanged();
    void    updateSideBarArea(const QRect&, int);

private:
    QWidget*            m_sideBar;
    TraceHighlighter    *syntaxHL;
    bool                specifiedLineNumber;
    bool                bsearchSelection;
    QTextEdit::ExtraSelection   searchSelection;
    QList<uint>         lineNumberList;
};

#endif // SNESTRACETEXTEDIT_H
