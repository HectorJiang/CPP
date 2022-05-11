QT       += core gui network charts

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
    cfilegraph.cpp \
    cfileserver.cpp \
    cfiletable.cpp \
    main.cpp

HEADERS += \
    cfilegraph.h \
    cfileserver.h \
    cfiletable.h

FORMS += \
    cfilegraph.ui \
    cfileserver.ui \
    cfiletable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RC_FILE += logo.rc
RC_ICONS += logo.ico

INCLUDEPATH += C:\\ENV\\opencv\\build\\include
INCLUDEPATH += C:\\ENV\\ffmpeg-4.4.2\\include

LIBS += -LC:\\ENV\\ffmpeg-4.4.2\\lib -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale
LIBS += -LC:\\ENV\\opencv\\build\\x64\\vc15\\lib\\ -lopencv_world455d
#LIBS += C:\ENV\opencv\build\x64\vc15\lib\opencv_world455

