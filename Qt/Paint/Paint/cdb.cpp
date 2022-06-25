#include "cdb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSQLError>
CDb::CDb()
{
	//���ÿɼ���
	m_pDb = QSqlDatabase::addDatabase("QSQLITE");
	m_pDb.setHostName("localhost");
	m_pDb.setDatabaseName("paint.db");//���ݿ��ļ���
	m_pDb.setUserName("root");
	m_pDb.setPassword("123456");
	//�����ݿ�
	openDb();
	//�������ݱ�
	createTable();
}


CDb::~CDb()
{
	//�ر����ݿ�
	m_pDb.close();
}



/*
�����ݿ�
*/
bool CDb::openDb() {
	if (!m_pDb.open()) {
		qDebug() << "Sqlite open failed";
		return false;
	}
	return true;
}



/*
�������ݿ��,���ж�paint���Ƿ����
*/
bool CDb::createTable() {
	QSqlQuery sqlquery;
	QString sql = QString("select * from sqlite_master where name='%1'").arg("paint");
	sqlquery.exec(sql);
	if (!sqlquery.next()) {
		//�����ھʹ�����
		QString sql = "create table paint("
					  "id integer PRIMARY KEY autoincrement,"
					  "pos varchar(256),"
					  "event varchar(256),"
					  "time TIMESTAMP default (datetime('now', 'localtime')))";
		if (!sqlquery.exec(sql)) {
			qDebug() << "Create table paint failed" << sqlquery.lastError();
			return false;
		}
	}
return true;
}


/*
��������
strPos: (x,y)
strEvent: move|click....
*/
bool CDb::insertData(QString strPos, QString strEvent)
{
	QSqlQuery sqlquery;
	sqlquery.prepare("INSERT INTO paint(pos, event) VALUES(:pos, :event)");
	sqlquery.bindValue(":pos", strPos);
	sqlquery.bindValue(":event", strEvent);
	if (!sqlquery.exec()) {
		qDebug() << "Insert data failed:" << sqlquery.lastError();
		return false;
	}
	return true;
}


