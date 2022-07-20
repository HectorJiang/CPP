#include "chectormainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CHectorMainWindow w;
    w.show();
    return a.exec();
}
