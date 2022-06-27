#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_cpaint.h"
#include <QMouseEvent>
#include <QLabel>
#include <QPainter>
#include <QSqlDatabase>
#include "cdbthread.h"
class CPaint : public QMainWindow
{
	Q_OBJECT
public:
	CPaint(QWidget *parent = Q_NULLPTR);
	~CPaint();
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseDoubleClickEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *e);

private:
	void setPainter(QPainter &);//设置Painter

signals:
	void sendMsgToSubThread(QString, QString);//发送消息给子线程

private:
	Ui::CPaintClass ui;
	QLabel *m_pLbPos;
	QLabel *m_pLbEvent;
	std::vector<QPoint> m_points;//线条组成点
	int m_iLength;//线条长度
	CDbThread *m_pThreadDb;//数据库线程
};
