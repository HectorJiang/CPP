#include "cinfodialog.h"

#include <QApplication>
#include <QFile>
#include <QTextCodec>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CInfoDialog w;
//    QFile qss("style.qss");
//    qss.open(QFile::ReadOnly);
//    a.setStyleSheet(qss.readAll());
//    qss.close();
    qApp->setStyleSheet("QLabel#m_pLbTipsUsername, QLabel#m_pLbTipsNumber, QLabel#m_pLbTipsEmail{color:red}");
    w.show();
    return a.exec();
}
