#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cpaint.h"
#include <QMouseEvent>
#include <QLabel>
#include <QSqlDatabase>
//#include "cdbthread.h"
class CPaint : public QMainWindow
{
	Q_OBJECT

public:
	CPaint(QWidget *parent = Q_NULLPTR);
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *e);
private:
	Ui::CPaintClass ui;
	QLabel *m_pLbPos;
	QLabel *m_pLbEvent;
	QSqlDatabase m_pDb;
	QString  m_sql;
	std::vector<std::vector<QPoint>> m_points;
	//std::vector<QPoint> m_points;
	QPoint m_pointStart;
	QPoint m_pointEnd;
	QColor m_clr;
	int weight;
	int style;
	//插入数据库的线程
	//CDbThread *dbthread;
};
