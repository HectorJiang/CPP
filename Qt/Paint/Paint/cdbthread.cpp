#include "cdbthread.h"
#include <QDebug>

CDbThread::CDbThread()
{
	m_Db = new CDb;
}

CDbThread::~CDbThread() {
	delete m_Db;
}

void CDbThread::run() {
	qDebug() << "subthread started";
}

void CDbThread::recMegFromMain(QString strPos, QString strEvent) {
	qDebug() << "Subthread received message is:" << "pos:" << strPos << ",event:" << strEvent;
	//²åÈëÊý¾Ý¿â
	m_Db->insertData(strPos, strEvent);
}