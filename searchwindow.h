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

#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QTextDocument>
#include <QWidget>
#include <QTextCursor>

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = 0);
    ~SearchWindow();

    void setDocument(QTextDocument *document);

    QTextCursor textCursor() const;
    void setTextCursor(QTextCursor textCursor);

signals:
    void    foundStuff(QTextCursor&);

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::SearchWindow *ui;

    QTextDocument *m_document;
    QTextCursor   m_textCursor;

    QStringList m_history;
};

#endif // SEARCHWINDOW_H
