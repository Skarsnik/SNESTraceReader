#include "traceeditsidebar.h"

TraceEditSidebar::TraceEditSidebar(SnesTraceTextEdit *parent) : QWidget(parent)
{
    m_traceEdit = parent;
}

void TraceEditSidebar::paintEvent(QPaintEvent *event)
{
    m_traceEdit->sideBarPaintEvent(event);
}

QSize TraceEditSidebar::sizeHint() const
{
    return QSize(m_traceEdit->sideBarAreaWidth(), 0);
}
