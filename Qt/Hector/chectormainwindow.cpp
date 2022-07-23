#include "chectormainwindow.h"
#include "ui_chectormainwindow.h"
#include <QDebug>
#include <QMoveEvent>
#include <QPixmap>
#include <QImage>
#include <QMessageBox>
#include <QStringLiteral>
#include <QGraphicsScene>

CHectorMainWindow::CHectorMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CHectorMainWindow)
{
    ui->setupUi(this);
    m_pLbImg = new QLabel(this);
    m_pLbImg->setFixedSize(85, 85);
    QImage *img = new QImage;
    img->load(":/images/resource/image/account.png");
    m_pLbImg->setPixmap(QPixmap::fromImage(*img));
//    m_ret = QRect(mapTo(this, this->geometry().topRight()+ QPoint(-85, 30)), QSize(85, 85));
    m_pLbImg->setGeometry(this->geometry().x()+this->width()-85, this->geometry().y()+30, 85, 85);

    QGraphicsScene scene;
    QGraphicsRectItem* pRectItem = scene.addRect(QRectF(0, 0, 100, 100));
    QGraphicsItem *pItem = scene.itemAt(50, 50,QTransform());
}

CHectorMainWindow::~CHectorMainWindow()
{
    delete ui;
}


void CHectorMainWindow::resizeEvent(QResizeEvent* event){
    qDebug() << "Main Window: " << this->geometry();
    m_pLbImg->setGeometry(this->width()-85, 30, 85, 85);
    qDebug() << m_pLbImg->geometry();
    m_pLbImg->raise();

}

void CHectorMainWindow::moveEvent(QMoveEvent *event){
}
