#include "cq3.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CQ3 w;
    QFile fileQSS(":/style.qss");
    if(fileQSS.open(QFile::ReadOnly)){
        qApp->setStyleSheet(QString(fileQSS.readAll()));
    }
    fileQSS.close();
    w.show();
    return a.exec();
}
