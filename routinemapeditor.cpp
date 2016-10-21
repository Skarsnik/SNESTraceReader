#include "routinemapeditor.h"
#include "ui_routinemapeditor.h"

RoutineMapEditor::RoutineMapEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoutineMapEditor)
{
    ui->setupUi(this);
    routinesFile = NULL;
}

RoutineMapEditor::~RoutineMapEditor()
{
    delete routinesFile;
    delete ui;
}

bool RoutineMapEditor::save(QString file)
{
    return routinesFile->save(file);
}
