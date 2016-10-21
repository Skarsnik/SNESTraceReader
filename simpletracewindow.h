#ifndef SIMPLETRACEWINDOW_H
#define SIMPLETRACEWINDOW_H

#include "tracehighlighter.h"

#include <QTextDocument>
#include <QWidget>
#include <QList>

namespace Ui {
class SimpleTraceWindow;
}

class SimpleTraceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SimpleTraceWindow(QWidget *parent = 0);
    ~SimpleTraceWindow();
    void    setLineNumbers(QList<uint>& lineNumbers);
    void    setText(QString text);

private:
    Ui::SimpleTraceWindow *ui;
};

#endif // SIMPLETRACEWINDOW_H
