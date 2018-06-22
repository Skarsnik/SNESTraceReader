#include "correctedscrolltreeview.h"
#include <QScrollBar>
#include <QDebug>

CorrectedScrollTreeView::CorrectedScrollTreeView(QWidget *parent) : QTreeView(parent)
{

}

void CorrectedScrollTreeView::scrollTo(const QModelIndex index, QAbstractItemView::ScrollHint hint)
{
    int horizPos = horizontalScrollBar()->value();

    qDebug() << "Scroll" << horizPos;
    QTreeView::scrollTo(index, hint);
    horizontalScrollBar()->setValue(horizPos);
}
