#include "searchwindow.h"
#include "ui_searchwindow.h"

SearchWindow::SearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::NoDropShadowWindowHint| Qt::Window);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::setDocument(QTextDocument *document)
{
    m_document = document;
}


void SearchWindow::on_pushButton_clicked()
{
    QString toSearch = ui->comboBox->currentText();
    QTextCursor foundCursor;

    m_history.append(toSearch);
    if (ui->directionHautradioButton->isChecked()) {
      foundCursor = m_document->find(toSearch, m_textCursor, QTextDocument::FindBackward);
    } else {
      foundCursor = m_document->find(toSearch, m_textCursor);
    }
    if (!foundCursor.isNull()) {
        m_textCursor = foundCursor;
        emit foundStuff(foundCursor);
    }
}
QTextCursor SearchWindow::textCursor() const
{
    return m_textCursor;
}

void SearchWindow::setTextCursor(QTextCursor textCursor)
{
    m_textCursor = textCursor;
}

