#ifndef READWRITEWINDOW_H
#define READWRITEWINDOW_H

#include <QMainWindow>
#include "stuffreadwrite.h"
#include <QListView>
#include <QTreeView>
#include <QMap>

namespace Ui {
class ReadWriteWindow;
}

class ReadWriteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReadWriteWindow(QWidget *parent = 0);
    ~ReadWriteWindow();

    void setMemoryRead(QMap<int, QList<lineInstr> > const &value);

    void setMemoryWrite(QMap<int, QList<lineInstr> > const &value);

    void    update();

    void    createListItem(QTreeView *lv, QMap<int, QList<lineInstr> > &map);

private:
    Ui::ReadWriteWindow *ui;

    QMap<int, QList<lineInstr> >   memoryRead;
    QMap<int, QList<lineInstr> >   memoryWrite;
};

#endif // READWRITEWINDOW_H
