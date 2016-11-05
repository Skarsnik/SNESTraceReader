#ifndef DISASSEMBLYWINDOW_H
#define DISASSEMBLYWINDOW_H

#include <QWidget>

namespace Ui {
class DisassemblyWindow;
}

class DisassemblyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisassemblyWindow(QWidget *parent = 0);
    ~DisassemblyWindow();

    void    setDisassembly(QString& text);

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::DisassemblyWindow *ui;
};

#endif // DISASSEMBLYWINDOW_H
