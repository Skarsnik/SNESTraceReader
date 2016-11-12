/*
 * Copyright (C) 2016 Sylvain "Skarsnik" Colinet

This software is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef WSNESTRACEREADER_H
#define WSNESTRACEREADER_H

#include <QMainWindow>
#include <QSettings>
#include "tracehighlighter.h"
#include "callcodeobject.h"
#include "calltreeitem.h"
#include "searchwindow.h"
#include "stuffreadwrite.h"
#include "snestracetextedit.h"
#include "disassemblylaunchwindow.h"

namespace Ui {
class WSNEStracereader;
}

class WSNEStracereader : public QMainWindow
{
    Q_OBJECT

public:
    explicit WSNEStracereader(QWidget *parent = 0);
    ~WSNEStracereader();

private slots:
    void on_actionOpen_triggered();

    void on_actionIndent_triggered();

    void on_callTreeView_doubleClicked(const QModelIndex &index);

    void on_actionSearch_triggered();

    void searchWindowFound(QTextCursor&);

    void on_cursorPositionChanged();

    void on_toolButton_clicked();


    void on_action_Quit_triggered();

    void on_actionShow_Read_Write_triggered();

    void on_actionDissamble_stuff_triggered();

private:
    Ui::WSNEStracereader *ui;
    SearchWindow *m_searchWindow;
    QString m_traceFile;
    DisassemblyLaunchWindow *disambleLaunchWindow;

    TraceHighlighter* syntaxHL;
    QMap<CallCodeObject *, CallTreeItem*> mapCallObjectItems;
    QSettings* m_settings;

    void indentLog();

    void createCallTree();
    QMap<int, QList<lineInstr> >   memoryRead;
    QMap<int, QList<lineInstr> >   memoryWrite;

    int indentLevel;
    void displayCall(CallCodeObject *item, uint indent);
    void createTreeModelItem(CallCodeObject *item, CallTreeItem *parent);

    void    findCallTreeItem(int lineNumber);

    void printMemoryTracking(const QMap<int, QList<lineInstr> > &track);

    void moveScrollBar();
    void createBufferWithRoutine(CallCodeObject *obj);
    void closeEvent(QCloseEvent *);
    void openTrace();
};

#endif // WSNESTRACEREADER_H
