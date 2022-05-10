#include "cfileserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CFileServer w;
    w.show();
    return a.exec();
}
