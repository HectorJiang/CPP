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
    copengl.cpp \
    main.cpp \
    chectormainwindow.cpp \
    glad.c

HEADERS += \
    chectormainwindow.h \
    copengl.h

FORMS += \
    chectormainwindow.ui

INCLUDEPATH += D:\ENV\opencv-4.5.5\build\include
INCLUDEPATH += D:\ENV\OpenGL\include

LIBS += D:\ENV\opencv-4.5.5\build\x64\vc15\lib\opencv_world455.lib
LIBS += D:\ENV\OpenGL\lib\glfw3.lib
#LIBS += opengl32.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
