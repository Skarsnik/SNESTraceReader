#ifndef ROUTINEMAPEDITOR_H
#define ROUTINEMAPEDITOR_H

#include <QWidget>
#include "routinemapfile.h"

namespace Ui {
class RoutineMapEditor;
}

class RoutineMapEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RoutineMapEditor(QWidget *parent = 0);
    ~RoutineMapEditor();
    bool    open(QString file);
    bool    save(QString file = QString());


private:
    Ui::RoutineMapEditor *ui;
    QList<RoutineEntry>*    routines;
    RoutineMapFile*         routinesFile;
};

#endif // ROUTINEMAPEDITOR_H
