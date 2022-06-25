QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    cq3.cpp

HEADERS += \
    cq3.h

FORMS += \
    cq3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qss.qrc

#DISTFILES += \
#    logo.rc


#可以在rc资源文件中添加版权以及图表等信息，当前在pro中添加，通过可设置rc文件为gbk或pro文件为gbk防止乱码，这里选择用pro文件
#RC_FILE += logo.rc

#图标
RC_ICONS = logo.ico
#版本信息
VERSION = 1.0.0
#公司名称
QMAKE_TARGET_COMPANY = "智器云南京信息科技有限公司"
#产品名称
QMAKE_TARGET_PRODUCT = "第二次考核Q3"
#文件说明
QMAKE_TARGET_DESCRIPTION = "第二次考核Q3"
#版权信息
QMAKE_TARGET_COPYRIGHT = "Copyright 2014-2021智器云南京信息科技有限公司"
#中文（简体）
RC_LANG = 0x0004

