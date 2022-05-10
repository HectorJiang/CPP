#include "cfileserver.h"
#include "ui_cfileserver.h"

#include <QDateTime>
#include <QFileDialog>


CFileServer::CFileServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CFileServer)
{
    ui->setupUi(this);
    setWindowTitle(tr("File Server"));
    m_bhead = true;
    m_pTcpServerFile = new QTcpServer(this);
    //开启监听
    connect(ui->m_pBtnListen, SIGNAL(clicked()), this, SLOT(listenSocket()));
    //客户端连接时的槽函数
    connect(m_pTcpServerFile, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(ui->m_pBtnStorePath, SIGNAL(clicked()), this, SLOT(selectStorePath()));
    connect(ui->m_pBtnOpenGraph, SIGNAL(clicked()), this, SLOT(showGraph()));
    connect(ui->m_pBtnOpenTable, SIGNAL(clicked()), this, SLOT(showTable()));
    logToTextBrowser("Info", "File Server Started");
}

CFileServer::~CFileServer()
{
    delete ui;
}

//输出日志
void CFileServer::logToTextBrowser(QString strLevel, QString strContent){
    //设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strResult = strLevel + ":" + strDateTime + ":" + strContent + "\n";
    ui->m_pTextBrowserLog->insertPlainText(strResult);//输出到textbrowser
    ui->m_pTextBrowserLog->moveCursor(QTextCursor::End);//将光标移动到当前文字最后
}

//开启监听
void CFileServer::listenSocket(){
    QString strIp = ui->m_pLeServerIp->text();
    quint16 strPort = ui->m_pLeServerPort->text().toUShort();
    qDebug()<<strIp<<strPort;
    m_pTcpServerFile->listen(QHostAddress(strIp), strPort);
//    qDebug() << m_pTcpServerFile->isListening();
    qDebug()<<m_pTcpServerFile->serverPort()<<m_pTcpServerFile->serverAddress();
    logToTextBrowser("Info", "Start listening");
}
//客户端连接时的槽函数
void CFileServer::acceptConnection(){
    //输出客户端连接日志
    logToTextBrowser("Info", "Client connected");
    //获取和客户端通信的套接字
    m_pTcpSocketFile = m_pTcpServerFile->nextPendingConnection();
    //客户端有数据的槽函数
    connect(m_pTcpSocketFile, SIGNAL(readyRead()), this, SLOT(receiveFile()));
}

//客户端有数据时的槽函数
void CFileServer::receiveFile(){
    //获取测试信息
    QByteArray buf = m_pTcpSocketFile->readAll();
    if(m_bhead){
        //如果是头，解析头（文件名，文件大小）
        QString str = QString(buf);
        logToTextBrowser("Info", str);
        QStringList strlist = str.split("&");
        m_strFileName = strlist.at(0);//解析帧头文件名
        m_iFileSize = strlist.at(1).toInt();//解析帧头文件大小
        m_bhead = false;//下次接收到的文件就是我们的数据
        m_iRecvSize = 0;
        m_ByteArrayFileBuf.clear();
        m_pTcpSocketFile->write("ok");
    }else{
        //根据文件名和文件大小接受和保存文件
        //根据文件名和文件大小接收和保存文件
        m_ByteArrayFileBuf.append(buf);
        m_iRecvSize += buf.size();//每接收一次文件，当前文件大小+1
        //当接收文件大小等于总文件大小，即文件数据接收完毕
        if (m_iRecvSize>=m_iFileSize)
        {
            //保存文件
//            m_pFile = new QFile(m_strFileName);
//        m_pFile->open(QIODevice::ReadWrite))
            QFile file(m_strPathName + '/' + m_strFileName);
            file.open(QIODevice::WriteOnly);
            file.write(m_ByteArrayFileBuf);
            file.close();
            m_bhead = true;
        }
    }
//    qDebug()<<msg;
}

//选择保存路径
void CFileServer::selectStorePath(){
    m_strPathName = QFileDialog::getExistingDirectory(this, "Choose store path", "../File");
    if(!m_strPathName.isEmpty()){
        ui->m_pLeStorePath->setText(m_strPathName);
        ui->m_pBtnListen->setEnabled(true);
    }
}

void CFileServer::showGraph(){
    CFileGraph *m_pFileGraph = new CFileGraph(this);
    m_pFileGraph->show();
}

void CFileServer::showTable(){
    CFileTable *m_pFileTable = new CFileTable(this);
    m_pFileTable->show();
}
