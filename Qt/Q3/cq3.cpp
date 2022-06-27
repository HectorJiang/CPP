#include "cq3.h"
#include "ui_cq3.h"

#include <QColorDialog>
#include <QFileDialog>
#include <QDebug>

CQ3::CQ3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CQ3)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/logo.ico"));
    //不可读效果：不可获得焦点
    ui->m_pLePath->setFocusPolicy(Qt::NoFocus);
    connect(ui->m_pBtnPath, SIGNAL(clicked()), this, SLOT(getPath()));
    connect(ui->m_pBtnColor, SIGNAL(clicked()), this, SLOT(getColor()));
    connect(ui->m_pListWidget, SIGNAL(currentRowChanged(int)), ui->m_pStackWidget, SLOT(setCurrentIndex(int)));
}

CQ3::~CQ3()
{
    delete ui;
}

void CQ3::getPath(){
    QString strFileName = QFileDialog::getOpenFileName();
    ui->m_pLePath->setText(strFileName);
}

void CQ3::getColor(){
    QColor color = QColorDialog::getColor();
    qDebug()<<color;
    ui->m_pLbColorPalatte->setAutoFillBackground(true);
    ui->m_pLbColorPalatte->setPalette(QPalette(color));
}
