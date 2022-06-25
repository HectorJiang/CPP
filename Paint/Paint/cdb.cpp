#include "cdb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSQLError>
CDb::CDb()
{
	//配置可加密
	m_pDb = QSqlDatabase::addDatabase("QSQLITE");
	m_pDb.setHostName("localhost");
	m_pDb.setDatabaseName("paint.db");//数据库文件名
	m_pDb.setUserName("root");
	m_pDb.setPassword("123456");
	//打开数据库
	openDb();
	//创建数据表
	createTable();
}


CDb::~CDb()
{
	//关闭数据库
	m_pDb.close();
}



/*
打开数据库
*/
bool CDb::openDb() {
	if (!m_pDb.open()) {
		qDebug() << "Sqlite open failed";
		return false;
	}
	return true;
}



/*
创建数据库表,先判断paint表是否存在
*/
bool CDb::createTable() {
	QSqlQuery sqlquery;
	QString sql = QString("select * from sqlite_master where name='%1'").arg("paint");
	sqlquery.exec(sql);
	if (!sqlquery.next()) {
		//不存在就创建表
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
插入数据
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


