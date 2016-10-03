#ifndef SIMPLETRACEWINDOW_H
#define SIMPLETRACEWINDOW_H

#include "tracehighlighter.h"

#include <QTextDocument>
#include <QWidget>

namespace Ui {
class SimpleTraceWindow;
}

class SimpleTraceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTraceWindow(QWidget *parent = 0);
    ~SimpleTraceWindow();

    QTextDocument* document();

private:
    Ui::SimpleTraceWindow *ui;

    TraceHighlighter *syntaxHL;
};

#endif // SIMPLETRACEWINDOW_H
