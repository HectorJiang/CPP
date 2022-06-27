#include "cpaint.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CPaint w;
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	w.show();
	return a.exec();
}
