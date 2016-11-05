#include "disassemblylaunchwindow.h"
#include "ui_disassemblylaunchwindow.h"
#include <QFileDialog>

DisassemblyLaunchWindow::DisassemblyLaunchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisassemblyLaunchWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);
    dispelProcess = new QProcess(this);
    dissWindow = new DisassemblyWindow(this);
    QObject::connect(dispelProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(on_Process_finished(int, QProcess::ExitStatus)));
    m_settings = new QSettings("skarsnik.nyo.fr", "SNESTracereader-Dispel");
    if (m_settings->contains("lastROM")) {
        romFile = m_settings->value("lastROM").toString();
        dispelExe = m_settings->value("dispelExe").toString();
        header = m_settings->value("hasHeader").toBool();
        loROM = m_settings->value("isLoROM").toBool();
        hiROM = m_settings->value("isHiROM").toBool();
        ui->romPathLineEdit->setText(romFile);
        ui->dispelLineEdit->setText(dispelExe);
        ui->headerCheckBox->setChecked(header);
        ui->loROMCheckBox->setChecked(loROM);
        ui->hiROMCheckBox->setChecked(hiROM);
    }
}

DisassemblyLaunchWindow::~DisassemblyLaunchWindow()
{
    delete ui;
}

void DisassemblyLaunchWindow::on_dispelPushButton_clicked()
{
    dispelExe = QFileDialog::getOpenFileName(this,
                                              tr("Pick dispel executable"), QString("D:/Project"), tr("Dispel.exe (*.exe)"));
    ui->dispelLineEdit->setText(dispelExe);
}

void DisassemblyLaunchWindow::on_romPushButton_clicked()
{
    romFile = QFileDialog::getOpenFileName(this,
                                              tr("Choose the SNES rom"), QString("D:/Emulation"), tr("SNES Rom (*.sfc, *smc)"));
    ui->romPathLineEdit->setText(romFile);
}

void DisassemblyLaunchWindow::on_Process_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    QString pstdout = dispelProcess->readAllStandardOutput();
    dissWindow->setDisassembly(pstdout);
    dissWindow->show();
}

void DisassemblyLaunchWindow::closeEvent(QCloseEvent *)
{
    m_settings->setValue("lastROM", romFile);
    m_settings->setValue("dispelExe", dispelExe);
    m_settings->setValue("hasHeader", header);
    m_settings->setValue("isHiROM", hiROM);
    m_settings->setValue("isLoROM", loROM);
}

void DisassemblyLaunchWindow::runDispell()
{
    hiROM = ui->hiROMCheckBox->isChecked();
    loROM = ui->loROMCheckBox->isChecked();
    header = ui->headerCheckBox->isChecked();

    if (dispelProcess != NULL || dispelProcess->state() != QProcess::NotRunning) {
      dispelProcess->kill();
    }
    QStringList arguments;
    if (hiROM)
        arguments << "-h";
    if (loROM)
        arguments << "-l";
    if (header)
        arguments << "-n";
    arguments << "-p";
    arguments << "-r";
    bool ok;
    arguments << ui->startLineEdit->text() + "-"  + QString::number(ui->startLineEdit->text().toInt(&ok, 16) + ui->sizeLineEdit->text().toInt(), 16);
    arguments << romFile;
    dispelProcess->start(dispelExe, arguments);
}

void DisassemblyLaunchWindow::on_pushButton_clicked()
{
    runDispell();
}
