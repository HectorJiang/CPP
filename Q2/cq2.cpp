#include "cq2.h"
#include "ui_cq2.h"

CQ2::CQ2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CQ2)
{
    ui->setupUi(this);
    connect(ui->m_pBtn, SIGNAL(clicked()), this, SLOT(changeStatus()));
    connect(ui->m_pBtnOk, SIGNAL(clicked()), this, SLOT(checkData()));
    connect(ui->m_pBtnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

CQ2::~CQ2()
{
    delete ui;
}

void CQ2::changeStatus(){
   if(m_bStatus){
       ui->m_pLeUsername->setEnabled(false);
       ui->m_pBtn->setText("start");
       m_bStatus = false;
   }else{
       ui->m_pLeUsername->setEnabled(true);
       ui->m_pBtn->setText("forbit");
       m_bStatus = true;
   }

}

void CQ2::checkData(){
    QRegExp regUsername = QRegExp("[0-9a-zA-Z]{6,}");
    bool bRes = regUsername.exactMatch(ui->m_pLeUsername->text());
    if(!bRes){
        ui->m_pLbUsernameTip->setText("格式错误 ");
        qApp->setStyleSheet("QLabel#m_pLbUsernameTip{color:red;}"
                            "QLineEdit#m_pLeUsername{border:2px solid red;}"
                            "QLineEdit#m_pLeUsername{background-image:url(:images/wrong.png);}"
                            "QLineEdit#m_pLeUsername{background-position:right;}"
                            "QLineEdit#m_pLeUsername{background-size:10px 20px;}"
                            "QLineEdit#m_pLeUsername{background-repeat: no-repeat;}"

                            );
    }
    if(bRes){
        ui->m_pLbUsernameTip->setText("");
        qApp->setStyleSheet("QLineEdit#m_pLeUsername{border:2px solid green;}"
                            "QLineEdit#m_pLeUsername{background-image:url(:images/right.png);}"
                            "QLineEdit#m_pLeUsername{background-position:right;}"
                            "QLineEdit#m_pLeUsername{background-repeat: no-repeat;}");
    }
}
