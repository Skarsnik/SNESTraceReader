#include "readwritewindow.h"
#include "ui_readwritewindow.h"

#include <QStandardItem>

ReadWriteWindow::ReadWriteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReadWriteWindow)
{
    ui->setupUi(this);

    ui->readTreeView->setSortingEnabled(true);
    ui->writeTreeView->setSortingEnabled(true);
    //QObject::connect(ui->readTreeView->header(), SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)), ui->readTreeView, SLOT(sortByColumn(int, Qt::SortOrder)));
}

ReadWriteWindow::~ReadWriteWindow()
{
    delete ui;
}

void ReadWriteWindow::setMemoryWrite(QMap<int, QList<lineInstr> > const &value)
{
    memoryWrite = value;
}

void ReadWriteWindow::update()
{
   createListItem(ui->readTreeView, memoryRead);
   createListItem(ui->writeTreeView, memoryWrite);
}

void ReadWriteWindow::createListItem(QTreeView *lv, QMap<int, QList<lineInstr> > &map)
{
    QStandardItemModel* model = new QStandardItemModel();
    lv->setModel(model);
    //model->setHeaderData(0, Qt::Horizontal, "Address", Qt::DisplayRole);
    //model->setHeaderData(1, Qt::Horizontal, "Interactions", Qt::DisplayRole);
    model->setHorizontalHeaderLabels(QStringList() << "Address" << "Number of interaction");
    QMapIterator<int, QList<lineInstr> > it(map);
    int rowCount = 0;
    while (it.hasNext()) {
        it.next();
        QStandardItem *pitem = new QStandardItem();
        pitem->setText("ADDR : " + QString::number(it.key(), 16));
        model->appendRow(pitem);

        QStandardItem *item2 = new QStandardItem();
        item2->setText(QString::number(it.value().size()));
        model->setItem(rowCount, 1, item2);

        foreach(lineInstr info, it.value()) {
            QStandardItem* lineItem = new QStandardItem();
            lineItem->setText(QString::number(info.lineNumber) + " - " + info.line);
            pitem->appendRow(lineItem);
        }
        rowCount++;
    }
    lv->expandAll();
    lv->resizeColumnToContents(0);
}

void ReadWriteWindow::setMemoryRead(QMap<int, QList<lineInstr> > const &value)
{
    memoryRead = value;
}
