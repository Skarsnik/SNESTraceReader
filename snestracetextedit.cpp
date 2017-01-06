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

#include "snestracetextedit.h"
#include "traceeditsidebar.h"

#include <QPainter>
#include <QDebug>

SnesTraceTextEdit::SnesTraceTextEdit(QWidget *parent) : QPlainTextEdit(parent)
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    setFont(font);
    syntaxHL = new TraceHighlighter(document());
    syntaxHL->setDocument(document());

    m_sideBar = new TraceEditSidebar(this);
    specifiedLineNumber = false;
    bsearchSelection = false;

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateSideBarAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateSideBarArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(on_cursorPositionChanged()));
}

int SnesTraceTextEdit::sideBarAreaWidth()
{
    int maxNumber = blockCount();
    if (specifiedLineNumber)
        maxNumber = lineNumberList.last() + 1;
    int digits = 1;
    int max = qMax(1, maxNumber);
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 5 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void SnesTraceTextEdit::sideBarPaintEvent(QPaintEvent *event)
{
    QPainter painter(m_sideBar);
    QColor bg(Qt::lightGray);
    bg = bg.lighter(120);
    painter.fillRect(event->rect(), bg);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            if (specifiedLineNumber) {
              number = QString::number(lineNumberList[blockNumber] + 1);
            }
            painter.setPen(QColor(Qt::black).lighter());
            painter.drawLine(m_sideBar->width() - 2, top, m_sideBar->width() - 2, bottom);
            painter.setPen(Qt::gray);
            painter.drawText(0, top, m_sideBar->width() - 2, fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

void SnesTraceTextEdit::resizeEvent(QResizeEvent *ev)
{
    QPlainTextEdit::resizeEvent(ev);

    QRect cr = contentsRect();
    m_sideBar->setGeometry(QRect(cr.left(), cr.top(), sideBarAreaWidth(), cr.height()));
}

void SnesTraceTextEdit::setCursorToLine(int lineNumber)
{
    QTextCursor cur = textCursor();
    QTextBlock b = document()->findBlockByLineNumber(lineNumber);
    cur.setPosition(b.position());
    cur.select(QTextCursor::LineUnderCursor);
    setTextCursor(cur);
    setFocus();
    qDebug() << "moved to line :" << lineNumber;
}

void SnesTraceTextEdit::updateSideBarAreaWidth(int)
{
    setViewportMargins(sideBarAreaWidth(), 0, 0, 0);
}

void SnesTraceTextEdit::updateSideBarArea(const QRect &rect, int dy)
{
    if (dy)
            m_sideBar->scroll(0, dy);
        else
            m_sideBar->update(0, rect.y(), m_sideBar->width(), rect.height());

        if (rect.contains(viewport()->rect()))
            updateSideBarAreaWidth(0);
}

void SnesTraceTextEdit::setSpecifiedLineNumber(bool value)
{
    specifiedLineNumber = value;
}

void SnesTraceTextEdit::setSearchSelection(const QTextEdit::ExtraSelection &sel)
{
    bsearchSelection = true;
    searchSelection = sel;
}

void SnesTraceTextEdit::setLineNumberList(const QList<uint> &value)
{
    lineNumberList = value;
    specifiedLineNumber = true;
    qDebug() << value;
}

void SnesTraceTextEdit::on_cursorPositionChanged()
{
    QList<QTextEdit::ExtraSelection> extraSelections;


    QTextEdit::ExtraSelection selection;
    QColor hl = QColor(Qt::lightGray).lighter(120);
    selection.format.setBackground(hl);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);
    if (bsearchSelection)
        extraSelections.append(searchSelection);
    setExtraSelections(extraSelections);
}
