#include "cq2.h"

#include <QApplication>
#include <QFile>
#include <Python.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CQ2 w;
    QFile qss(":/style.qss");
    qss.open(QFile::ReadOnly);
    //QByteArray to QString
    a.setStyleSheet(qss.readAll());
    qss.close();

//    QFile fileQSS(":/style.qss");
//    if(fileQSS.open(QFile::ReadOnly)){
//        qApp->setStyleSheet(QString(fileQSS.readAll()));
//    }
//    fileQSS.close();
    Py_Initialize();
    PyRun_SimpleString("print(121)");
    w.show();
    return a.exec();
}
