#include "fileserver.h"
#include "ui_fileserver.h"

FileServer::FileServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileServer)
{
    ui->setupUi(this);
    setWindowTitle(tr("File Server"));

//    connect(ui, SIGNAL())

}

FileServer::~FileServer()
{
    delete ui;
}

//void FileServer::disconnect(){

//}


void FileServer::dataReceice(){

}

void FileServer::slotDisconnected(){

}
