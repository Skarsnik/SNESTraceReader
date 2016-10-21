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

private slots:
    void    updateSideBarAreaWidth(int);
    void    on_cursorPositionChanged();
    void    updateSideBarArea(const QRect&, int);

private:
    QWidget*            m_sideBar;
    TraceHighlighter    *syntaxHL;
    bool                specifiedLineNumber;
    QList<uint>         lineNumberList;
};

#endif // SNESTRACETEXTEDIT_H
