#include "wsnestracereader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WSNEStracereader w;
    w.show();

    return a.exec();
}
