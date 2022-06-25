#pragma once
#include <QThread>
#include "cdb.h"

class CDbThread :public QThread
{
	Q_OBJECT
public:
	CDbThread();
	~CDbThread();
protected:
	void run();
public slots:
	//接受主线程消息
	void recMegFromMain(QString, QString);
private:
	//声明一个db
	CDb *m_Db;
};

