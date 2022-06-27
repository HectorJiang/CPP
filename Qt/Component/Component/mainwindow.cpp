#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QWidget *m_pComboBox = new QWidget(this);
    m_pComboBox->resize(220, 50);
    QWidget *widgetTag = new QWidget(this);
    widgetTag->setStyleSheet("width: 220px;"
                             "height: 32px;"
                             "background: #FFFFFF;"
                            "border: 1px solid rgba(134,144,156,1);");
    QLabel *lbTag = new QLabel("火眼金睛", this);
    lbTag->setSy
    QHBoxLayout *layoutWidgetTag = new QHBoxLayout();
    layoutWidgetTag->addWidget(lbTag);
    widgetTag->setLayout(layoutWidgetTag);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(widgetTag);
    m_pComboBox->setLayout(layout);



//    connect(ui->m_pBtnAddLabel, SIGNAL(clicked()), this, SLOT(addLabel()));
//    connect(ui->m_pBtnAddLabel, SIGNAL(clicked()), ui->listView, SLOT(hide()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addLabel(){
//    QLabel *label = new QLabel("test1", this);
//    layout->addWidget(label);
}
