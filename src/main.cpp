#include "wid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wid w;
    w.show();

    return a.exec();
}
