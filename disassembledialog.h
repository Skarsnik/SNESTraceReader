#ifndef DISASSEMBLEDIALOG_H
#define DISASSEMBLEDIALOG_H

#include <QDialog>

namespace Ui {
class DisassembleDialog;
}

class DisassembleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DisassembleDialog(QWidget *parent = 0);
    ~DisassembleDialog();

private slots:
    void on_dispelPushButton_clicked();

    void on_romPushButton_clicked();

private:
    Ui::DisassembleDialog *ui;

    QString dispelExe;
    QString romFile;

    bool    loROM;
    bool    hiROM;
    bool    header;

    void    runDispell();
};

#endif // DISASSEMBLEDIALOG_H
