#include "cpaint.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QLinearGradient>
#include <QColor>
#include <QGradient>

CPaint::CPaint(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pLbPos = new QLabel(this);
	m_pLbEvent = new QLabel(this);
	m_pLbPos->setFixedWidth(100);
	m_pLbEvent->setFixedWidth(100);
	m_pLbPos->setAlignment(Qt::AlignLeft);
	m_pLbEvent->setAlignment(Qt::AlignLeft);
	statusBar()->addPermanentWidget(m_pLbPos);
	statusBar()->addPermanentWidget(m_pLbEvent);
	m_pLbPos->setText("x: ,y ");
	m_pLbEvent->setText(" ");
	this->setMouseTracking(true);
	//设置线条长度
	m_iLength = 20;
	//创建线程
	m_pThreadDb = new CDbThread;
	//启动线程
	m_pThreadDb->start();
	m_pThreadDb->wait();
	connect(this, &CPaint::sendMsgToSubThread, m_pThreadDb, &CDbThread::recMegFromMain);

}

CPaint::~CPaint(){
	//线程一直开启，直到最后退出
	m_pThreadDb->quit();
}

/*
鼠标单击事件
*/
void CPaint::mousePressEvent(QMouseEvent * e)
{
	QString strPos = "(" + QString::number(e-> x()) + "," + QString::number(e->y()) + ")";
	QString strEvent;
	if (e->button() == Qt::LeftButton) strEvent = "Left press";
	else if (e->button() == Qt::RightButton) strEvent = "Right press";
	else if (e->button() == Qt::MidButton) strEvent = "Mid press";
	m_pLbPos->setText(strPos);
	m_pLbEvent->setText(strEvent);
	//发送数据给子线程
	emit sendMsgToSubThread(strPos, strEvent);
}

/*
鼠标释放事件
*/
void CPaint::mouseReleaseEvent(QMouseEvent *e) {
	QString strPos = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
	QString strEvent;
	if (e->button() == Qt::LeftButton) strEvent = "Left release";
	else if (e->button() == Qt::RightButton) strEvent = "Right release";
	else if (e->button() == Qt::MidButton) strEvent = "Mid release";
	m_pLbPos->setText(strPos);
	m_pLbEvent->setText(strEvent);
	//发送数据给子线程
	emit sendMsgToSubThread(strPos, strEvent);
}

/*
鼠标移动事件
*/
void CPaint::mouseMoveEvent(QMouseEvent *e) {
	QString strPos = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
	QString strEvent = "move";
	m_pLbPos->setText(strPos);
	m_pLbEvent->setText(strEvent);
	//发送数据给子线程
	emit sendMsgToSubThread(strPos, strEvent);
	//将移动的QPoint添加到m_points，绘制线条
	m_points.push_back(e->pos());
	update();
}

/*
鼠标双击事件
*/
void CPaint::mouseDoubleClickEvent(QMouseEvent *e) {
	QString strPos = "(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
	QString strEvent;
	if (e->button() == Qt::LeftButton) strEvent = "Left dclick";
	else if (e->button() == Qt::RightButton) strEvent = "Right dclick";
	else if (e->button() == Qt::MidButton) strEvent = "Mid dclick";
	m_pLbPos->setText(strPos);
	m_pLbEvent->setText(strEvent);
	//发送数据给子线程
	emit sendMsgToSubThread(strPos, strEvent);
}

/*
line的长度一定，满了就隐藏头部；
每次重绘，采用for循环
*/
void CPaint::paintEvent(QPaintEvent *e) {
	QPainter painter(this);
	setPainter(painter);
	//限制line的显示，长度为m_iLength
	if (m_points.size() > 1 && m_points.size()<= m_iLength)
		for (int i = 1;i < m_points.size() - 1; i++) {
			painter.drawLine(m_points[i - 1], m_points[i]);
		}
	else if (m_points.size() > m_iLength) {
		//每超出一个点就隐藏vector开始的一个点
		for (int i = m_points.size()- m_iLength+1; i < m_points.size() - 1; i++) {
			painter.drawLine(m_points[i - 1], m_points[i]);
		}
	}
}

void CPaint::setPainter(QPainter &painter) {
	painter.setRenderHint(QPainter::Antialiasing, true);//反走样
	// 设置渐变色
	QLinearGradient linear(QPointF(0, 0), QPointF(width(), height()));
	linear.setColorAt(0, QColor(Qt::green));
	linear.setColorAt(0.6, QColor(Qt::blue));
	linear.setColorAt(1, QColor(Qt::red));
	painter.setPen(QPen(linear, 5));// 设置画笔颜色、宽度
}