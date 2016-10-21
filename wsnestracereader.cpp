#include "wsnestracereader.h"
#include "ui_wsnestracereader.h"
#include "calltreeitem.h"
#include "simpletracewindow.h"

#include <QThread>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QStandardItemModel>
#include <QTextDocumentFragment>
#include <QScrollBar>
#include <QWindow>
#include <QMessageBox>
#include <QProgressDialog>
#include "callcodeobject.h"

WSNEStracereader::WSNEStracereader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WSNEStracereader)
{
    ui->setupUi(this);

    m_searchWindow = new SearchWindow(this);
    m_searchWindow->hide();

    addDockWidget(Qt::LeftDockWidgetArea, ui->callTreeDockWidget);
    addDockWidget(Qt::RightDockWidgetArea, ui->routineDockWidget);
    addDockWidget(Qt::RightDockWidgetArea, ui->ramMapDockWidget);

    ui->callTreeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    QObject::connect(m_searchWindow, SIGNAL(foundStuff(QTextCursor&)), this, SLOT(searchWindowFound(QTextCursor&)));
    QObject::connect(ui->traceTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(on_cursorPositionChanged()));
    indentLevel = 5;


    m_settings = new QSettings("skarsnik.nyo.fr", "SNESTracereader");




    if (m_settings->contains("windowGeometry"))
    {
        restoreGeometry(m_settings->value("windowGeometry").toByteArray());
        restoreState(m_settings->value("windowState").toByteArray());
    }
    //ui->traceTextEdit->document()->setIndentWidth(20);
    m_traceFile = "D:/Emulation/Lua/testcall.log";
    openTrace();
    qDebug() << "READ STUFF";
    printMemoryTracking(memoryRead);
    qDebug() << "WRITE STUFF";
    printMemoryTracking(memoryWrite);
    qDebug() << "End memory";
    //indentLog();
}

WSNEStracereader::~WSNEStracereader()
{
    delete ui;
}


void WSNEStracereader::on_actionOpen_triggered()
{
    m_traceFile = QFileDialog::getOpenFileName(this,
                                               tr("Open Trace"), QString("D:/Emulation/Lua"), tr("Trace file (*.txt *.log)"));
    if (!m_traceFile.isEmpty()) {
        openTrace();
    }
}

void WSNEStracereader::openTrace() {
    QFile trace(m_traceFile);
    memoryRead.clear();
    memoryWrite.clear();

    if (trace.open(QFile::ReadOnly | QFile::Text))
    {
        int lineSize;
        int fileSize = trace.size();
        ui->traceTextEdit->clear();

        QProgressDialog progress("Loading trace file", QString(), 0, fileSize, this);
        progress.setWindowModality(Qt::WindowModal);
        progress.setValue(0);

        QString line = trace.readLine();
        ui->traceTextEdit->appendPlainText(line);
        lineSize = line.size();
        int numberOfRead = int(fileSize / (10000 * lineSize));
        progress.setMaximum(numberOfRead * 1.2);
        int nbRead = 1;
        while(!trace.atEnd()) {
            QByteArray data = trace.read(lineSize * 10000);
            QTextCursor tc = ui->traceTextEdit->textCursor();
            tc.insertText(data);
            //ui->traceTextEdit->appendPlainText(data);
            progress.setValue(nbRead);
            nbRead++;
        }
        progress.setValue(numberOfRead);
        progress.setLabelText("Building pseudo call tree");
        progress.setValue(numberOfRead * 1.1);
        qDebug() << "Start building Call tree";
        createCallTree();
        qDebug() << "End building Call tree";
        progress.setValue(numberOfRead * 1.2);
        QTextCursor cur(ui->traceTextEdit->document());
        cur.movePosition(QTextCursor::Start);
        ui->traceTextEdit->setTextCursor(cur);

    }
    setWindowTitle("SNES Trace reader - " + m_traceFile);
    return;
}

void WSNEStracereader::indentLog()
{
    //bool change;
    QTextBlock b = ui->traceTextEdit->document()->firstBlock();

    QTextCursor cursor(b);

    while (b.isValid()) {
       cursor.setPosition(b.position());
       QTextBlockFormat bformat = cursor.blockFormat();


       bformat.setIndent(indentLevel);
       //bformat.setBackground(Qt::red);
       cursor.setBlockFormat(bformat);
       //cursor.mergeBlockFormat(bformat);
       QString inst = b.text().mid(7,3);
       if (inst == "jsr" || inst == "jsl" || inst == "jml") {
            indentLevel++;
            //qDebug() << indentLevel;
       }
       if (inst == "rtl" || inst == "rts" || inst == "rti") {
           indentLevel--;
           //qDebug() << indentLevel;
       }
       b = b.next();

    }
    /*b = ui->traceTextEdit->document()->firstBlock();
    while (b.isValid()) {

       b = b.next();
       qDebug() << b.length() <<b.blockFormat().indent();
    }*/
}

void WSNEStracereader::createCallTree()
{
  CallCodeObject *root = new CallCodeObject();
  QFile trace(m_traceFile);
  if (trace.open(QFile::ReadOnly | QFile::Text)) {
      CallCodeObject *current = root;
      //CallCodeObject *oldroot = root;
      //bool           returnInRoot = false;
      root->parent = NULL;
      root->start_addr = "Dummy";
      root->stop_addr = "Dummy";
      root->start_line = 0;
      int lineNumber = 0;
      while (!trace.atEnd()) {
          QByteArray line = trace.readLine();
          //qDebug() << lineNumber << line;
          line.chop(1);
          QString instr = line.mid(7, 3);

          if (instr == "jsr" || instr == "jsl" || instr == "jml") {
              qDebug() << line;
              QString jaddr = line.mid(12, 6);
              CallCodeObject* newCC = new CallCodeObject();
              current->children.append(newCC);
              newCC->parent = current;
              newCC->start_line = lineNumber + 1;
              newCC->start_addr = jaddr;
              newCC->stop_addr = "Unknow";
              newCC->stop_line = - 1;
              current = newCC;
          }
          if (instr == "rtl" || instr == "rts" || instr == "rti") {
              qDebug() << lineNumber << line;
              current->stop_addr = line.mid(0, 6);
              current->stop_line = lineNumber;
              if (current == root) {
                  CallCodeObject *newroot = new CallCodeObject();
                  newroot->children.append(root);
                  newroot->start_addr = "Dummy";
                  newroot->stop_addr = "Dummy";
                  newroot->start_line = lineNumber;
                  root->parent = newroot;
                  root = newroot;
              }
              current = current->parent;
          }
          if (instr == "lda" || instr == "ldx" || instr == "ldy") {
              bool ok;
              if (line.mid(21, 1) == "[") {
                int addr = line.mid(22, 6).toInt(&ok, 16);
                lineInstr nl;
                nl.line = line;
                nl.lineNumber = lineNumber;
                memoryRead[addr].append(nl);
              }
          }
          if (instr == "sda" || instr == "sdx" || instr == "sdy") {
              bool ok;
              if (line.mid(21, 1) == "[") {
                int addr = line.mid(23, 6).toInt(&ok, 16);
                lineInstr nl;
                nl.line = line;
                nl.lineNumber = lineNumber;
                memoryWrite[addr].append(nl);
              }
          }


          lineNumber++;
      }
      current->stop_line = lineNumber - 1;
      displayCall(root, 0);


      QStandardItemModel* model = new QStandardItemModel();
      CallTreeItem* iRoot = (CallTreeItem*) model->invisibleRootItem();
      CallTreeItem* realRoot = new CallTreeItem();
      realRoot->setData(root);
      mapCallObjectItems.insert(root, realRoot);
      iRoot->appendRow(realRoot);
      createTreeModelItem(root, realRoot);
      ui->callTreeView->setModel(model);
  }

}

void WSNEStracereader::createTreeModelItem(CallCodeObject *item, CallTreeItem* parent) {
    if (!item->children.empty()) {
        foreach(CallCodeObject* child, item->children) {
            CallTreeItem *newItemChild = new CallTreeItem();
            newItemChild->setData(child);
            mapCallObjectItems.insert(child, newItemChild);
            parent->appendRow(newItemChild);
            createTreeModelItem(child, newItemChild);
        }
    }
}


void WSNEStracereader::displayCall(CallCodeObject *item, uint indent) {
    qDebug() << QString(indent * 2, ' ') << "Start:" << item->start_addr;
    if (!item->children.empty()) {
        foreach(CallCodeObject* child, item->children) {
           displayCall(child, indent + 1);
        }
    }
    qDebug() << QString(indent * 2, ' ') << "End  :" << item->stop_addr;
}

void WSNEStracereader::on_actionIndent_triggered()
{
    indentLog();
}

void WSNEStracereader::on_callTreeView_doubleClicked(const QModelIndex &index)
{
    QStandardItemModel* model = (QStandardItemModel*) ui->callTreeView->model();
    CallTreeItem* item = (CallTreeItem*) model->itemFromIndex(index);
    CallCodeObject *call = item->data();
    ui->traceTextEdit->setCursorToLine(call->start_line);
}


void WSNEStracereader::printMemoryTracking(const QMap<int, QList<lineInstr> > &track)
{
    QMapIterator<int, QList<lineInstr> > it(track);
    while (it.hasNext()) {
        it.next();
        qDebug() << "0x" + QString::number(it.key(), 16);
        foreach(lineInstr info, it.value()) {
            qDebug() << "  Line :" + QString::number(info.lineNumber) + " -> " + info.line;
        }
    }
}

void WSNEStracereader::on_actionSearch_triggered()
{
    m_searchWindow->setDocument(ui->traceTextEdit->document());
    m_searchWindow->setTextCursor(ui->traceTextEdit->textCursor());
    m_searchWindow->show();
}

void WSNEStracereader::searchWindowFound(QTextCursor &tc)
{
    qDebug() << "Found stuff";
    ui->traceTextEdit->setTextCursor(tc);

    ui->traceTextEdit->setFocus();

    QTextBlock b = tc.block();
    int lineNumber = b.firstLineNumber();

    QMapIterator<CallCodeObject*, CallTreeItem*> i(mapCallObjectItems);

    qDebug() << lineNumber << mapCallObjectItems.size();
    bool inIn = false;
    while (inIn == false && i.hasNext()) {
        i.next();
        bool inChild = false;
        //CallTreeItem* item = i.value();
        CallCodeObject *obj = i.key();
        qDebug() << obj->start_addr << obj->start_line << obj->stop_line;
        if (lineNumber > obj->start_line && lineNumber <= obj->stop_line) {
            foreach (CallCodeObject* child, obj->children) {
                if ((lineNumber > child->start_line && lineNumber <= obj->stop_line)) {
                    inChild = true;
                    break;
                }
            }
            if (inChild == false) {
              inIn = true;
              qDebug() << "found it";
            }
        }
    }
    if (inIn) {
        CallTreeItem* item = i.value();
        //CallCodeObject *obj = i.key();
        qDebug() << item->index();
        ui->callTreeView->setExpanded(item->index(), true);
        ui->callTreeView->scrollTo(item->index());
        ui->callTreeView->setCurrentIndex(item->index());
    }
}

void WSNEStracereader::on_cursorPositionChanged()
{
    QTextBlock b = ui->traceTextEdit->textCursor().block();
    int lineNumber = b.firstLineNumber();
    ui->statusBar->showMessage("Line : " + QString::number(lineNumber + 1));
}

void WSNEStracereader::moveScrollBar() {
    int cursorY = ui->traceTextEdit->cursorRect().top();
    qDebug() << cursorY;
    QScrollBar *vbar = ui->traceTextEdit->verticalScrollBar();
    vbar->setValue(cursorY);
}

void WSNEStracereader::on_toolButton_clicked()
{
    QStandardItemModel* model = (QStandardItemModel*) ui->callTreeView->model();
    CallTreeItem* item = (CallTreeItem*) model->itemFromIndex(ui->callTreeView->currentIndex());
    CallCodeObject* obj = item->data();
    createBufferWithRoutine(obj);
}

void WSNEStracereader::createBufferWithRoutine(CallCodeObject* obj) {
    SimpleTraceWindow *w = new SimpleTraceWindow(this);
    QList<uint> listLineNumber;
    QString text;
    w->setWindowTitle("Simple Trace - " + obj->start_addr);
    int lineCount = ui->traceTextEdit->document()->lineCount();
    int lineNumber = obj->start_line;
    bool hasChild = false;
    CallCodeObject *child;

    //FIXME Need to handle Dummy root item that have start line after their first child
    //qDebug() << "children count : " << obj->children.size();
    QListIterator<CallCodeObject*> it(obj->children);
    if (!obj->children.empty()) {
        hasChild = true;
        child = it.next();
    }

    while (obj->stop_line == 0 && lineNumber < ui->traceTextEdit->document()->blockCount()
           || lineNumber <= obj->stop_line
           || (obj->stop_line == -1 && lineNumber < lineCount)) {
        QTextBlock b = ui->traceTextEdit->document()->findBlockByLineNumber(lineNumber);
        text.append(b.text() + "\n");
        listLineNumber.append(lineNumber);
        if (hasChild && lineNumber + 1 == child->start_line) {
            if (child->stop_line == -1)
                lineNumber = lineCount;
            else
                lineNumber = child->stop_line + 1;
            if (it.hasNext())
                child = it.next();
        } else {
            lineNumber++;
        }    
    }
    text.chop(1);
    qDebug() << listLineNumber.size();
    w->setText(text);
    w->setLineNumbers(listLineNumber);
    w->show();
}

void WSNEStracereader::closeEvent(QCloseEvent *)
{
    m_settings->setValue("windowState", saveState());
    m_settings->setValue("windowGeometry", saveGeometry());
}

void WSNEStracereader::on_action_Quit_triggered()
{
    qApp->exit();
}
