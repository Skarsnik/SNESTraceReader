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

private:
    Ui::SearchWindow *ui;

    QTextDocument *m_document;
    QTextCursor   m_textCursor;

    QStringList m_history;
};

#endif // SEARCHWINDOW_H
