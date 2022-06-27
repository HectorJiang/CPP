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
	void setPainter(QPainter &);//����Painter

signals:
	void sendMsgToSubThread(QString, QString);//������Ϣ�����߳�

private:
	Ui::CPaintClass ui;
	QLabel *m_pLbPos;
	QLabel *m_pLbEvent;
	std::vector<QPoint> m_points;//������ɵ�
	int m_iLength;//��������
	CDbThread *m_pThreadDb;//���ݿ��߳�
};
