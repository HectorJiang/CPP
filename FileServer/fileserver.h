#ifndef FILESERVER_H
#define FILESERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class FileServer; }
QT_END_NAMESPACE

class FileServer : public QMainWindow
{
    Q_OBJECT

public:
    FileServer(QWidget *parent = nullptr);
    ~FileServer();
    //输出日志到TextBrowser
    void logToTextBrowser(QString strLevel, QString strContent);

private slots:
    void listenSocket();
    void acceptConnection();
    //接收文件
    void receiveFile();
    //选择保存路径
    void selectStorePath();


private:
    Ui::FileServer *ui;
    QTcpSocket *m_pTcpSocketFile;//TcpSocket
    QTcpServer *m_pTcpServerFile;//TcpServer
    QString m_strPathName;//保存路径
    QString m_strFileName;//文件名；
    bool m_bhead;//是否是文件头
    int  m_iFileSize;//接收文件的总大小
    int m_iRecvSize;//当前接受文件的大小
    QByteArray m_ByteArrayFileBuf;
};
#endif // FILESERVER_H
