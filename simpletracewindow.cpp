#include "simpletracewindow.h"
#include "ui_simpletracewindow.h"
#include "tracehighlighter.h"
#include <QDebug>

SimpleTraceWindow::SimpleTraceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimpleTraceWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);


    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->traceTextEdit->setFont(font);

    syntaxHL = new TraceHighlighter(ui->traceTextEdit->document());
    syntaxHL->setDocument(ui->traceTextEdit->document());
}

SimpleTraceWindow::~SimpleTraceWindow()
{
    delete ui;
}

QTextDocument* SimpleTraceWindow::document()
{
    return ui->traceTextEdit->document();
}

