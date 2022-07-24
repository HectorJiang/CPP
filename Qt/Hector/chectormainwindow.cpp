#include "chectormainwindow.h"
#include "ui_chectormainwindow.h"
#include <QDebug>
#include <QMoveEvent>
#include <QPixmap>
#include <QImage>
#include <QMessageBox>
#include <QStringLiteral>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QToolBar>
#include <QFileDialog>
#include <opencv2/opencv.hpp>

CHectorMainWindow::CHectorMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_pActionExit(nullptr)
//    , ui(new Ui::CHectorMainWindow)
{
//    ui->setupUi(this);
//    m_pLbImg = new QLabel(this);
//    m_pLbImg->setFixedSize(85, 85);
//    QImage *img = new QImage;
//    img->load(":/images/resource/image/account.png");
//    m_pLbImg->setPixmap(QPixmap::fromImage(*img));
//    m_ret = QRect(mapTo(this, this->geometry().topRight()+ QPoint(-85, 30)), QSize(85, 85));
//    m_pLbImg->setGeometry(this->geometry().x()+this->width()-85, this->geometry().y()+30, 85, 85);
    initUI();
    createActions();
}

CHectorMainWindow::~CHectorMainWindow()
{
//    delete ui;
}


void CHectorMainWindow::initUI(){
    this->resize(800, 600);
    //setup menubar
    m_pMenuFile = menuBar()->addMenu("&File");
    m_pMenuView = menuBar()->addMenu("&View");

    //setup toolbar
    m_pToolBarFile = addToolBar("File");
    m_pToolBarView = addToolBar("View");

    //setup action
    m_pActionOpen = new QAction("&Open", this);
    m_pActionExit = new QAction("&Exit", this);
    m_pActionZoomIn = new QAction("&ZoomIn", this);
    m_pMenuFile->addAction(m_pActionOpen);
    m_pMenuFile->addAction(m_pActionExit);
    m_pToolBarFile->addAction(m_pActionOpen);

    m_pMenuView->addAction(m_pActionZoomIn);

    //main area for image display
    m_pSceneImage = new QGraphicsScene(this);
    m_pViewImage = new QGraphicsView(m_pSceneImage);
    setCentralWidget(m_pViewImage);

    //setup status bar
    m_pStatusBarMain = statusBar();
    m_pLbMainStatus = new QLabel(m_pStatusBarMain);
    m_pStatusBarMain->addPermanentWidget(m_pLbMainStatus);
    m_pLbMainStatus->setText("Image Information will be here!");
}

void CHectorMainWindow::createActions(){
    //cannot bind a undefined
    connect(m_pActionExit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(m_pActionOpen, SIGNAL(triggered(bool)), this, SLOT(openImage()));
    connect(m_pActionZoomIn, SIGNAL(triggered(bool)), this, SLOT(zoomIn()));
}

void CHectorMainWindow::openImage(){
    QFileDialog dialogImage(this);
    dialogImage.setWindowTitle("Open Image");
    dialogImage.setFileMode(QFileDialog::ExistingFile);
    dialogImage.setNameFilter(tr("Images(*.png *.bmp *.jpg"));
    QStringList strFilePaths;
    if(dialogImage.exec()){
        strFilePaths = dialogImage.selectedFiles();
        showImage(strFilePaths.at(0));
    }
    std::string current_locale_text = strFilePaths.at(0).toLocal8Bit().constData();
    cv::Mat img = cv::imread(current_locale_text);
    if(!img.empty()){
        cv::namedWindow("Hector", cv::WINDOW_AUTOSIZE);
        cv::imshow("Hector", img);
        cv::waitKey(0);
        cv::destroyWindow("Hector");
    }
}

void CHectorMainWindow::showImage(QString strPath){
    m_pSceneImage->clear();
    m_pViewImage->resetMatrix();
    QPixmap pixmapImage(strPath);
    m_pSceneImage->addPixmap(pixmapImage);
    m_pSceneImage->update();
    m_pViewImage->setSceneRect(pixmapImage.rect());
    QString status = QString("%1, %2x%3, %4 Bytes").arg(strPath).arg(pixmapImage.width())
            .arg(pixmapImage.height()).arg(QFile(strPath).size());
    m_pLbMainStatus->setText(status);
}

void CHectorMainWindow::zoomIn(){
    m_pViewImage->scale(1.2, 1.2);
}

void CHectorMainWindow::resizeEvent(QResizeEvent* event){
//    qDebug() << "Main Window: " << this->geometry();
//    m_pLbImg->setGeometry(this->width()-85, 30, 85, 85);
//    qDebug() << m_pLbImg->geometry();
//    m_pLbImg->raise();

}

void CHectorMainWindow::moveEvent(QMoveEvent *event){
}
