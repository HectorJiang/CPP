#ifndef FILECLIENT_H
#define FILECLIENT_H

#include <QFile>
#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class FileClient; }
QT_END_NAMESPACE

class FileClient : public QMainWindow
{
    Q_OBJECT

public:
    FileClient(QWidget *parent = nullptr);
    ~FileClient();

private slots:
    //连接服务器
    void connectServer();
    //选择文件
    void selectFile();
    //发送文件
    void sendFile();
    //发送文件进度
    void sendFileProgress(qint64);

private:
    Ui::FileClient *ui;
//    QTcpSocket *m_pTcpSocket;
    QTcpSocket *m_pTcpSocketFile;
    QFile *m_pFile;
    QString m_strFileName;
    //文件大小
    qint64 m_bytesTotal;
    //已发送文件字节数
    qint64 m_bytesWritten;
    //文件名字节数
    qint64 m_sizeFileName;
    //每次发送数据大小
    qint64 m_sizeSendOnce;
    //数据缓冲区
    QByteArray m_byteArrayIn;
    QByteArray m_byteArrayOut;
};
#endif // FILECLIENT_H
