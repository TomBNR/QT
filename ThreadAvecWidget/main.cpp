#include "threadavecwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThreadAvecWidget w;
    w.show();
    return a.exec();
}
