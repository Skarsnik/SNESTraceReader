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

private:
    Ui::DisassembleDialog *ui;
};

#endif // DISASSEMBLEDIALOG_H
