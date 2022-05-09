/********************************************************************************
** Form generated from reading UI file 'fileclient.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECLIENT_H
#define UI_FILECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileClient
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QProgressBar *progressBar;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *m_pBtnSelectFile;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QPushButton *m_pBtnSendFile;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FileClient)
    {
        if (FileClient->objectName().isEmpty())
            FileClient->setObjectName(QString::fromUtf8("FileClient"));
        FileClient->resize(800, 600);
        centralwidget = new QWidget(FileClient);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 190, 342, 217));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(100);
        progressBar->setValue(27);

        gridLayout->addWidget(progressBar, 4, 0, 1, 3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 2);

        m_pBtnSelectFile = new QPushButton(layoutWidget);
        m_pBtnSelectFile->setObjectName(QString::fromUtf8("m_pBtnSelectFile"));

        gridLayout->addWidget(m_pBtnSelectFile, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pBtnSendFile = new QPushButton(layoutWidget);
        m_pBtnSendFile->setObjectName(QString::fromUtf8("m_pBtnSendFile"));

        gridLayout->addWidget(m_pBtnSendFile, 3, 0, 1, 1);

        FileClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FileClient);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        FileClient->setMenuBar(menubar);
        statusbar = new QStatusBar(FileClient);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FileClient->setStatusBar(statusbar);

        retranslateUi(FileClient);

        QMetaObject::connectSlotsByName(FileClient);
    } // setupUi

    void retranslateUi(QMainWindow *FileClient)
    {
        FileClient->setWindowTitle(QCoreApplication::translate("FileClient", "FileClient", nullptr));
        label_2->setText(QCoreApplication::translate("FileClient", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        pushButton->setText(QCoreApplication::translate("FileClient", "\350\277\236\346\216\245", nullptr));
        m_pBtnSelectFile->setText(QCoreApplication::translate("FileClient", "\351\200\211\346\213\251\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("FileClient", "\346\234\215\345\212\241\345\231\250IP", nullptr));
        m_pBtnSendFile->setText(QCoreApplication::translate("FileClient", "\344\270\212\344\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileClient: public Ui_FileClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECLIENT_H
