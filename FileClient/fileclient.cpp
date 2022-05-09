#include "fileclient.h"
#include "ui_fileclient.h"

FileClient::FileClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileClient)
{
    ui->setupUi(this);
    //    connect(ui->m_pBtnSelectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
    //    connect(ui->m_pBtnSendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
}

FileClient::~FileClient()
{
    delete ui;
}

void FileClient::connectServer(){

}

void FileClient::sendData(){

}
void FileClient::receiveData(){

}
void FileClient::selectFile(){

}

void FileClient::sendFile(){

}
void FileClient::sendFileProgress(){

}
