#ifndef CFILESERVER_H
#define CFILESERVER_H

#include "cfilegraph.h"
#include "cfiletable.h"
#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class CFileServer; }
QT_END_NAMESPACE

class CFileServer : public QMainWindow
{
    Q_OBJECT

public:
    CFileServer(QWidget *parent = nullptr);
    ~CFileServer();
    //输出日志到TextBrowser
    void logToTextBrowser(QString strLevel, QString strContent);

private slots:
    void listenSocket();
    void acceptConnection();
    //接收文件
    void receiveFile();
    //选择保存路径
    void selectStorePath();
    //展示图表
    void showGraph();
    void showTable();
private:
    Ui::CFileServer *ui;
    QTcpSocket *m_pTcpSocketFile;//TcpSocket
    std::shared_ptr<QTcpServer> *m_pTcpServerFile;//TcpServer
    QString m_strPathName;//保存路径
    QString m_strFileName;//文件名；
    bool m_bhead;//是否是文件头
    int  m_iFileSize;//接收文件的总大小
    int m_iRecvSize;//当前接受文件的大小
    QByteArray m_ByteArrayFileBuf;

};
#endif // FILESERVER_H
