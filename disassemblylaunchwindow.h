#ifndef DISASSEMBLYLAUNCHWINDOW_H
#define DISASSEMBLYLAUNCHWINDOW_H

#include <QProcess>
#include <QSettings>
#include <QWidget>
#include "disassemblywindow.h"

namespace Ui {
class DisassemblyLaunchWindow;
}

class DisassemblyLaunchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisassemblyLaunchWindow(QWidget *parent = 0);
    ~DisassemblyLaunchWindow();


private slots:
    void on_dispelPushButton_clicked();

    void on_romPushButton_clicked();

    void on_Process_finished(int exitCode, QProcess::ExitStatus exitStatus);

    void on_pushButton_clicked();

private:
    Ui::DisassemblyLaunchWindow *ui;

    QProcess*           dispelProcess;
    DisassemblyWindow*  dissWindow;

    QString dispelExe;
    QString romFile;
    void closeEvent(QCloseEvent *);

    QSettings* m_settings;

    bool    loROM;
    bool    hiROM;
    bool    header;

    void    runDispell();
};

#endif // DISASSEMBLYLAUNCHWINDOW_H
