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
    //向服务器发送数据
    void sendData();
    //接收服务器数据
    void receiveData();

    void selectFile();
    void sendFile();
    void sendFileProgress();
private:
    Ui::FileClient *ui;
    QTcpSocket *m_pTcpSocket;
    QFile *m_pFile;
};
#endif // FILECLIENT_H
