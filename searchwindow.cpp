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

#include "searchwindow.h"
#include "ui_searchwindow.h"
#include <QDebug>
#include <QTextBlock>

SearchWindow::SearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::NoDropShadowWindowHint| Qt::Window);
    ui->comboBox->setFocus();
    QObject::connect((QObject*)ui->comboBox->lineEdit(), SIGNAL(returnPressed()), this, SLOT(on_comboLineEditReturnPressed()));
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
    search();
}

void SearchWindow::search()
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
        ui->infoLabel->setText(QString("Match found at line %1").arg(foundCursor.block().firstLineNumber()));
        emit foundStuff(foundCursor);
        if (ui->comboBox->findText(toSearch) == -1)
          ui->comboBox->addItem(toSearch);
    } else {
        ui->infoLabel->setText("<b>No match found</b>");
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


void SearchWindow::on_comboLineEditReturnPressed()
{
    search();
}
