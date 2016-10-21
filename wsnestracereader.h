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

private:
    Ui::WSNEStracereader *ui;
    SearchWindow *m_searchWindow;
    QString m_traceFile;

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

    void printMemoryTracking(const QMap<int, QList<lineInstr> > &track);

    void moveScrollBar();
    void createBufferWithRoutine(CallCodeObject *obj);
    void closeEvent(QCloseEvent *);
    void openTrace();
};

#endif // WSNESTRACEREADER_H
