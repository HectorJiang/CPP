#include "fileserver.h"
#include "ui_fileserver.h"

#include <QDateTime>
#include <QFileDialog>


FileServer::FileServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileServer)
{
    ui->setupUi(this);
    setWindowTitle(tr("File Server"));
    //文件传输套接字
    m_pTcpSocketFile = new QTcpSocket(this);
    m_pTcpServerFile = new QTcpServer(this);
    QString strIp = ui->m_pLeServerIp->text();
    qint16 strPort = ui->m_pLeServerPort->text().toInt();
    //开启监听
    m_pTcpServerFile->listen(QHostAddress(strIp), strPort);
    connect(m_pTcpServerFile, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(ui->m_pBtnStorePath, SIGNAL(clicked()), this, SLOT(selectStorePath()));
    logToTextBrowser("Info", "File Server Start");
}

FileServer::~FileServer()
{
    delete ui;
}

//输出日志
void FileServer::logToTextBrowser(QString strLevel, QString strContent){
    //设置输出信息格式
    QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString strResult = strLevel + ":" + strDateTime + ":" + strContent + "\n";
    ui->m_pTextBrowserLog->insertPlainText(strResult);//输出到textbrowser
    ui->m_pTextBrowserLog->moveCursor(QTextCursor::End);//将光标移动到当前文字最后
}

void FileServer::acceptConnection(){

}
void FileServer::receiveFile(){

}

//选择保存路径
void FileServer::selectStorePath(){
    m_strPathName = QFileDialog::getExistingDirectory(this, "Choose store path", "../File");
    if(!m_strPathName.isEmpty()){
        ui->m_pLeStorePath->setText(m_strPathName);
        ui->m_pBtnListen->setEnabled(true);
    }
}

