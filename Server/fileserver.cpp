#include "fileserver.h"
#include "ui_fileserver.h"

FileServer::FileServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FileServer)
{
    ui->setupUi(this);
}

FileServer::~FileServer()
{
    delete ui;
}

