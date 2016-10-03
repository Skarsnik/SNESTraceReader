#include "disassembledialog.h"
#include "ui_disassembledialog.h"

DisassembleDialog::DisassembleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisassembleDialog)
{
    ui->setupUi(this);
}

DisassembleDialog::~DisassembleDialog()
{
    delete ui;
}
