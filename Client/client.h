#ifndef CLIENT_H
#define CLIENT_H

#include <QFile>
#include <QMainWindow>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
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
    Ui::Client *ui;
    QTcpSocket *m_pTcpSocket;
    QFile *m_pFile;

};
#endif // CLIENT_H
