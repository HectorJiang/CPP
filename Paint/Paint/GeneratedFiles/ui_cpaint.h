/********************************************************************************
** Form generated from reading UI file 'cpaint.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPAINT_H
#define UI_CPAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPaintClass
{
public:
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CPaintClass)
    {
        if (CPaintClass->objectName().isEmpty())
            CPaintClass->setObjectName(QString::fromUtf8("CPaintClass"));
        CPaintClass->resize(600, 400);
        centralWidget = new QWidget(CPaintClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CPaintClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CPaintClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CPaintClass->setStatusBar(statusBar);

        retranslateUi(CPaintClass);

        QMetaObject::connectSlotsByName(CPaintClass);
    } // setupUi

    void retranslateUi(QMainWindow *CPaintClass)
    {
        CPaintClass->setWindowTitle(QCoreApplication::translate("CPaintClass", "Paint", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CPaintClass: public Ui_CPaintClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPAINT_H
