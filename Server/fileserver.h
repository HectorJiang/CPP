#ifndef FILESERVER_H
#define FILESERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FileServer; }
QT_END_NAMESPACE

class FileServer : public QMainWindow
{
    Q_OBJECT

public:
    FileServer(QWidget *parent = nullptr);
    ~FileServer();

private:
    Ui::FileServer *ui;
};
#endif // FILESERVER_H
