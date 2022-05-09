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
    void acceptConnection();
    //接收文件
    void receiveFile();
    //选择保存路径
    void selectStorePath();

private:
    Ui::FileServer *ui;
    QTcpSocket *m_pTcpSocketFile;
    QTcpServer *m_pTcpServerFile;
    QString m_strPathName;
};
#endif // FILESERVER_H
