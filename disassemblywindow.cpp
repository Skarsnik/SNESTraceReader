#include "disassemblywindow.h"
#include "ui_disassemblywindow.h"
#include "asmsyntaxhl.h"

DisassemblyWindow::DisassemblyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisassemblyWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);

    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(12);

    ASMSyntaxHL* syntaxHL = new ASMSyntaxHL(ui->ASMPlainTextEdit->document());
    syntaxHL->setDocument(ui->ASMPlainTextEdit->document());

    ui->ASMPlainTextEdit->setFont(font);
}

DisassemblyWindow::~DisassemblyWindow()
{
    delete ui;
}

void DisassemblyWindow::setDisassembly(QString &text)
{
    ui->ASMPlainTextEdit->clear();
    ui->ASMPlainTextEdit->appendPlainText(text);

    QTextCursor cur(ui->ASMPlainTextEdit->document());
    cur.movePosition(QTextCursor::Start);
    ui->ASMPlainTextEdit->setTextCursor(cur);

}

void DisassemblyWindow::on_pushButton_2_clicked()
{
    close();
}
