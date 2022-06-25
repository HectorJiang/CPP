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
    connect(m_pTcpSocketFile, SIGNAL(bytesWritten(qint64)), this, SLOT(sendFileProgress(qint64)));
}

FileClient::~FileClient()
{
    delete ui;
}

//连接服务器
void FileClient::connectServer(){
    QString strIp = ui->m_pLeServerIp->text();
    quint16 strPort = ui->m_pLeServerPort->text().toUShort();
    m_pTcpSocketFile->connectToHost(strIp, strPort);
    qDebug()<<strIp<<strPort;
    //建立连接之后发送一条测试消息
//    connect(m_pTcpSocketFile, SIGNAL(connected()), this, SLOT(sendTestMessage()));
    //建立连接之后上传按钮可以用了，状态栏改变
    connect(m_pTcpSocketFile, SIGNAL(connected()), this, SLOT(connectSuccess()));
//    connect(m_pTcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

//选择文件
void FileClient::selectFile(){
    m_strFileName = QFileDialog::getOpenFileName(this, "Choose file path");
    if(!m_strFileName.isEmpty()){
        ui->m_pLeFile->setText(m_strFileName);
        ui->m_pProgressBar->setValue(0);
//        ui->m_pBtnSendFile->setEnabled(true);
    }
}

//发送文件
void FileClient::sendFile(){
//    m_pFile = new QFile(m_strFileName);
//    //获取文件大小
//    m_bytesTotal = m_pFile->size();
//    qDebug()<<"File Size:"<<m_bytesTotal;
//    QDataStream m_dataStream(&m_byteArrayOut, QIODevice::WriteOnly);
//    //无路径文件名
//    QString m_strLastFileName = m_strFileName.right(m_strFileName.size()-m_strFileName.lastIndexOf('/')-1);
//    qDebug()<<m_strLastFileName<<sizeof(m_strLastFileName);
//    m_dataStream.device()->seek(0);
//    m_bytesWritten = m_pTcpSocketFile->write(m_byteArrayOut);
//    //清空发送缓冲区
//    m_byteArrayOut.resize(0);
    QFileInfo info(m_strFileName);
    //用QFileInfo：：fileName，size获取文件名和大小 格式：文件名&大小
    //服务器用该格式解析文件名和大小
    QString head = QString("%1&%2").arg(info.fileName()).arg(info.size());
    //将该格式发送给服务器 toUtf8：QString转QByteArray或char类型
    m_pTcpSocketFile->write(head.toUtf8());
}


void FileClient::sendFileProgress(qint64 bytesNum){
    //已发送文件字节数
    m_bytesWritten += (int)bytesNum;
    qDebug()<<"BytesWritten:"<<m_bytesWritten;
    if(m_bytesWritten > 0){

    }
}


void FileClient::sendTestMessage(){
    m_pTcpSocketFile->write("test message");
}


void FileClient::connectSuccess(){
    ui->statusbar->showMessage("Connected to file server!!!", 5000);
    ui->m_pBtnSendFile->setEnabled(true);
    connect(m_pTcpSocketFile, SIGNAL(readyRead()), this, SLOT(replyServer()));
}


void FileClient::replyServer(){
    //读取服务器发送的信息（即缓冲区信息）
    QByteArray buf = m_pTcpSocketFile->readAll();
    if (buf=="ok")
    {
            m_pFile = new QFile(m_strFileName);
        if (!m_pFile->open(QIODevice::ReadWrite))
        {
            //读取文件失败
            return;
        }
        qint64 currentlen = 0;//当前已经发送的大小
        qint64 allLength = m_pFile->size();//总文件大小
        while (currentlen < allLength)//当发送文件等于文件大小时，发送完毕，循环结束
        {
            char data[1024];
            qint64 msize = m_pFile->read(data, 1024);//读文件放入打他数组中，返回读取到的大小
            m_pTcpSocketFile->write(data, msize);//把读取到的data数据发送给服务器
            currentlen += msize;//实时获取当前发送的文件大小
            ui->m_pProgressBar->setValue(currentlen *100 / allLength);//更新界面进度条
        }
    }
}
