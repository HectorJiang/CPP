#include "fileclient.h"
#include "ui_fileclient.h"

#include <QFileDialog>
#include <QDebug>

FileClient::FileClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileClient)
{
    ui->setupUi(this);
    setWindowTitle(tr("File Client"));
    m_pTcpSocketFile = new QTcpSocket(this);
    ui->m_pProgressBar->setValue(0);
    ui->m_pBtnSendFile->setEnabled(false);
    connect(ui->m_pBtnConnect, SIGNAL(clicked()), this, SLOT(connectServer()));
    connect(ui->m_pBtnSelectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->m_pBtnSendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
    connect(m_pTcpSocketFile, SIGNAL(bytesWritten(qint64)), this, SLOT(sendFileProgress()));
}

FileClient::~FileClient()
{
    delete ui;
}

//连接服务器
void FileClient::connectServer(){
    QString strIp = ui->m_pLeServerIp->text();
    qint16 strPort = ui->m_pLeServerPort->text().toInt();
    m_pTcpSocketFile->connectToHost(strIp, strPort);
    qDebug()<<strIp<<strPort;
//    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

//选择文件
void FileClient::selectFile(){
    m_strFileName = QFileDialog::getOpenFileName(this, "Choose file path");
    if(!m_strFileName.isEmpty()){
        ui->m_pLeFile->setText(m_strFileName);
        ui->m_pBtnSendFile->setEnabled(true);
    }
}

//发送文件
void FileClient::sendFile(){
    m_pFile = new QFile(m_strFileName);
    //获取文件大小
    m_bytesTotal = m_pFile->size();
    qDebug()<<"File Size:"<<m_bytesTotal;
    QDataStream m_dataStream(&m_byteArrayOut, QIODevice::WriteOnly);
    QString m_strLastFileName = m_strFileName.right(m_strFileName.size()-m_strFileName.lastIndexOf('/')-1);
    qDebug()<<sizeof(m_strLastFileName);
    m_dataStream.device()->seek(0);
    m_bytesWritten = m_pTcpSocketFile->write(m_byteArrayOut);
    //清空发送缓冲区
    m_byteArrayOut.resize(0);
}


void FileClient::sendFileProgress(qint64 bytesNum){
    //已发送文件字节数
    m_bytesWritten += (int)bytesNum;
    qDebug()<<"BytesWritten:"<<m_bytesWritten;
    if(m_bytesWritten > 0){

    }
}
