#ifndef CORRECTEDSCROLLTREEVIEW_H
#define CORRECTEDSCROLLTREEVIEW_H

#include <QTreeView>
#include <QWidget>

class CorrectedScrollTreeView : public QTreeView
{
Q_OBJECT
public:

    CorrectedScrollTreeView(QWidget *parent = 0);
    void scrollTo(const QModelIndex index, ScrollHint hint = EnsureVisible);
};

#endif // CORRECTEDSCROLLTREEVIEW_H
