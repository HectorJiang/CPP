#include "cpaint.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
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
	//启动插入数据库线程
	//dbthread->start();
	//dbthread->wait();
	m_pDb = QSqlDatabase::addDatabase("QSQLITE");
	m_pDb.setHostName("localhost");
	m_pDb.setDatabaseName("paint.db");
	m_pDb.setUserName("root");
	m_pDb.setPassword("123456");
	m_pDb.open();
	m_sql = "insert into paint(pos, event) values(%1,%2)";
	//QSqlQuery m_sql;
	//bool success = m_sql.exec("create table paint(id int primary key,pos int,event varchar,time timestamp)");
	//qDebug() << success;
}

void CPaint::mousePressEvent(QMouseEvent * e)
{
	QString strPos = "(" + QString::number(e-> x()) + "," + QString::number(e->y()) + ")";
	QSqlQuery query;
	QString strEvent;
	//strEvent = e->button() == Qt::LeftButton ? "Left press" : (e->button() == Qt::RightButton ? "Right press" : "Mid press");
	if (e->button() == Qt::LeftButton) strEvent = "Left press";
	else if (e->button() == Qt::RightButton) strEvent = "Right press";
	else if (e->button() == Qt::MidButton) strEvent = "Mid press";
	m_pLbPos->setText(strPos);
	m_pLbEvent->setText(strEvent);
	//QString m_sql = m_sql.arg(strPos, strEvent);
	//bool bRes = query.exec(m_sql);
	//qDebug() << bRes;
	//std::vector<QPoint> point;
	//point.push_back(e->pos());
	//m_points.push_back(e->pos());
}

void CPaint::mouseMoveEvent(QMouseEvent *e) {
	m_pLbPos->setText("(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")");
	m_pLbEvent->setText("move");
	auto &point = m_points[m_points.size() - 1];
	point.push_back(e->pos());
	m_points.push_back(point);
	update();
	//QPen pen;
	//pen.setWidth(weight);
	//pen.setColor(m_clr);
	//QPainter *painter = new QPainter;
	//painter->setPen(pen);
	//painter->drawLine(m_pointStart, e->pos());
	//m_pointEnd = e->pos();
}

void CPaint::mouseReleaseEvent(QMouseEvent *e) {
	m_pLbPos->setText("(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")");
	if (e->button() == Qt::LeftButton) m_pLbEvent->setText("Left release");
	else if (e->button() == Qt::RightButton) m_pLbEvent->setText("Right release");
	else if (e->button() == Qt::MidButton) m_pLbEvent->setText("Mid release");
	//auto &point = m_points[m_points.size() - 1];
	//point.push_back(e->pos());
}

void CPaint::mouseDoubleClickEvent(QMouseEvent *e) {
	m_pLbPos->setText("(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")");
	if (e->button() == Qt::LeftButton) m_pLbEvent->setText("Left dclick");
	else if (e->button() == Qt::RightButton) m_pLbEvent->setText("Right dclick");
	else if (e->button() == Qt::MidButton) m_pLbEvent->setText("Mid dclick");
	//auto &point = m_points[m_points.size() - 1];
	//point.push_back(e->pos());
}

void CPaint::paintEvent(QPaintEvent *e) {
	QPainter painter(this);
	//painter.setPen(QPen(Qt::red, 5));
	//painter.setRenderHint(QPainter::Antialiasing, true);
	QLinearGradient linear(100, 100, 200, 100);
	linear.setColorAt(0, QColor(145, 218, 204));
	linear.setColorAt(1, QColor(47, 141, 237));
	//linear.setSpread(QGradient::PadSpread);
	painter.setPen(QPen(QColor(255, 255, 255, 0), 1));
	painter.setBrush(QBrush(linear));
	//painter.setPen
	//for (const auto &point : m_points) {
	//	for (int i = 1; i < point.size() - 1; i++) {
	//		painter.drawLine(point.at(i-1), point.at(i));
	//	}
	//}
	//painter.drawRect(QRect(100, 100, 200, 100));
	painter.drawLine(0, 0, 200, 200);
}