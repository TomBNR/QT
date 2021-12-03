#include "dietetique.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dietetique w;
    w.show();
    return a.exec();
}
