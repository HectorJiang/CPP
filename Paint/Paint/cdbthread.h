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
	//�������߳���Ϣ
	void recMegFromMain(QString, QString);
private:
	//����һ��db
	CDb *m_Db;
};

