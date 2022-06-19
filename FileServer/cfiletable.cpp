#include "cfiletable.h"
#include "ui_cfiletable.h"

CFileTable::CFileTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CFileTable)
{
    ui->setupUi(this);
}

CFileTable::~CFileTable()
{
    delete ui;
}
