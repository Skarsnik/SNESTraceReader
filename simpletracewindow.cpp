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
}

SimpleTraceWindow::~SimpleTraceWindow()
{
    delete ui;
}

void    SimpleTraceWindow::setLineNumbers(QList<uint> &lineNumbers)
{
    ui->tracePlainTextEdit->setLineNumberList(lineNumbers);
}

void SimpleTraceWindow::setText(QString text)
{
    ui->tracePlainTextEdit->setPlainText(text);
}

