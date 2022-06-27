#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(QString(":/qss/mainwindow.qss"));
    file.open(QFile::ReadOnly);
    MainWindow w;
    w.setStyleSheet(file.readAll());
    file.close();
    w.show();
    return a.exec();
}
