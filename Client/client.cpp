#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
//    connect(ui->m_pBtnSelectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
//    connect(ui->m_pBtnSendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
}

Client::~Client()
{
    delete ui;
}

