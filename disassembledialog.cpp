#include "disassembledialog.h"
#include "ui_disassembledialog.h"
#include <QFileDialog>

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

void DisassembleDialog::on_dispelPushButton_clicked()
{
    dispelExe = QFileDialog::getOpenFileName(this,
                                              tr("Pick dispel executable"), QString("D:/Project"), tr("Dispel.exe (*.exe)"));
    ui->dispelLineEdit->setText(dispelExe);
}

void DisassembleDialog::runDispell()
{

}

void DisassembleDialog::on_romPushButton_clicked()
{
    romFile = QFileDialog::getOpenFileName(this,
                                              tr("Choose the SNES rom"), QString("D:/Emulation"), tr("SNES Rom (*.sfc, *smc)"));
    ui->romPathLineEdit->setText(romFile);
}
