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
