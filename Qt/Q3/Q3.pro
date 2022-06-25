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


#������rc��Դ�ļ�����Ӱ�Ȩ�Լ�ͼ�����Ϣ����ǰ��pro����ӣ�ͨ��������rc�ļ�Ϊgbk��pro�ļ�Ϊgbk��ֹ���룬����ѡ����pro�ļ�
#RC_FILE += logo.rc

#ͼ��
RC_ICONS = logo.ico
#�汾��Ϣ
VERSION = 1.0.0
#��˾����
QMAKE_TARGET_COMPANY = "�������Ͼ���Ϣ�Ƽ����޹�˾"
#��Ʒ����
QMAKE_TARGET_PRODUCT = "�ڶ��ο���Q3"
#�ļ�˵��
QMAKE_TARGET_DESCRIPTION = "�ڶ��ο���Q3"
#��Ȩ��Ϣ
QMAKE_TARGET_COPYRIGHT = "Copyright 2014-2021�������Ͼ���Ϣ�Ƽ����޹�˾"
#���ģ����壩
RC_LANG = 0x0004

