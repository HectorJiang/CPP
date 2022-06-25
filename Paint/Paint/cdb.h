#pragma once
#include <QObject>
#include <QSqlDatabase>
class CDb : public QObject
{
	Q_OBJECT
public:
	CDb();
	~CDb();
	bool openDb();
	bool createTable();
	bool insertData(QString, QString);
	
private:
	QSqlDatabase m_pDb;
	QString  m_sql;
};
