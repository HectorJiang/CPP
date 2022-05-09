#ifndef FILESERVER_H
#define FILESERVER_H

#include <QMainWindow>
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

signals:
    void disconnect(int);
protected slots:
    void dataReceice();
    void slotDisconnected();

private:
    Ui::FileServer *ui;
    QTcpSocket *m_pTcpSocket;
};
#endif // FILESERVER_H
