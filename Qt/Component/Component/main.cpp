#include "combobox.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ComboBox w;
	QFile qss(":/stylesheet.qss");
	if (qss.open(QFile::ReadOnly)) {
		QString style = QLatin1String(qss.readAll());
		qDebug() << "Successed to read stylesheet qss";
		qDebug() << style;
		a.setStyleSheet(style);
		qss.close();
	}
	else qDebug() << "Failed to read stylesheet.qss";
	w.show();
	return a.exec();
}
