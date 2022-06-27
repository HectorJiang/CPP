#include "cinfodialog.h"
#include "ui_cinfodialog.h"
#include <QDebug>
#include <QException>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
CInfoDialog::CInfoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CInfoDialog)
{
    ui->setupUi(this);
    //设置提示自动换行
    ui->m_pLbTipsUsername->setWordWrap(true);
    ui->m_pLbTipsNumber->setWordWrap(true);
    ui->m_pLbTipsEmail->setWordWrap(true);
    connect(ui->m_pBtnOk, SIGNAL(clicked()), this, SLOT(validateInfo()));
    connect(ui->m_pBtnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

CInfoDialog::~CInfoDialog()
{
    delete ui;
}

//验证信息
void CInfoDialog::validateInfo(){
    //清空提示信息
    ui->m_pLbTipsUsername->setText("");
    ui->m_pLbTipsNumber->setText("");
    ui->m_pLbTipsEmail->setText("");
    m_pStrUsername = ui->m_pLeUsername->text();
    m_pStrNumber = ui->m_pLeNumber->text();
    m_pStrEmail = ui->m_pLeEmail->text();
    QRegExp reUsername = QRegExp("[a-zA-Z0-9]{6,}");
    QRegExp reNumber = QRegExp("[0-9]{11}");//手机号简单的11位认证
    QRegExp reEmail = QRegExp("[a-zA-Z0-9\_]+@[a-zA-Z0-9\_]+.com");
//    QPalette pe;
//    pe.setColor(QPalette::WindowText, Qt::red);
//    ui->m_pLbTipsUsername->setPalette(pe);
//    ui->m_pLbTipsNumber->setPalette(pe);
//    ui->m_pLbTipsEmail->setPalette(pe);

    if(!reUsername.exactMatch(m_pStrUsername))
        ui->m_pLbTipsUsername->setText(QString::fromUtf8("用户名格式为:大小写字母和数字，长度最少为6"));
    if(!reNumber.exactMatch(m_pStrNumber))
        ui->m_pLbTipsNumber->setText(QString::fromUtf8("手机号码格式错误，长度为11"));
    if(!reEmail.exactMatch(m_pStrEmail))
        ui->m_pLbTipsEmail->setText(QString::fromUtf8("邮箱格式错误"));
    qDebug()<<reUsername.exactMatch(m_pStrUsername);
    qDebug()<<reNumber.exactMatch(m_pStrNumber);
    qDebug()<<reEmail.exactMatch(m_pStrEmail);
    if(reUsername.exactMatch(m_pStrUsername) && reNumber.exactMatch(m_pStrNumber) && reEmail.exactMatch(m_pStrEmail))
        //验证通过保存文件
        saveInfoToJson();
}

//验证通过之后保存到json
void CInfoDialog::saveInfoToJson(){
    QString fileName = QFileDialog::getSaveFileName(this, "保存到JSON ", "info.json", "*.json");
    //点击确定 内容写入JSON
    if(!fileName.isEmpty()){
        QFile fileJSON(fileName);
//        if(!QFile::exists(fileName)) fileJSON.open(QFile::WriteOnly);
        //构建JSON内容
        QJsonObject jsonObj{
            {"username", m_pStrUsername},
            {"number", m_pStrNumber},
            {"email", m_pStrEmail}
        };
        QJsonDocument *jsonDoc = new QJsonDocument(jsonObj);
        try {
            fileJSON.open(QFile::WriteOnly);
            qDebug()<<jsonDoc->toJson();
            fileJSON.write(jsonDoc->toJson());
        } catch (QException &e) {
            //弹出提示对话框
            qDebug()<<e.what();
            QMessageBox::critical(this, "出错", "JSON文件保存出错", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            fileJSON.close();
        }
        fileJSON.close();
    }
    qDebug()<<fileName;
}

