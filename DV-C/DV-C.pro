#-------------------------------------------------
#
# Project created by QtCreator 2018-12-04T11:29:50
#
#-------------------------------------------------

QT += core gui opengl

TARGET = DV-C
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.

#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++14
CONFIG += c++14

macx {
    QMAKE_CFLAGS_X86_64 += -macosx-version-min=10.7
    QMAKE_CXXFLAGS_X86_64 = $$QMAKE_CFLAGS_X86_64
    CONFIG += c++11
}

INCLUDEPATH += Jellyfish UI glm glew-1.10.0/include
DEPENDPATH += Jellyfish UI glm glew-1.10.0/include

SOURCES += \
    UI/main.cpp \
    UI/mainwindow.cpp \
    UI/glwidget.cpp \
    glew-1.10.0/src/glew.c \
    glData/vbo.cpp \
    glData/vao.cpp \
    Jellyfish/jellyfish.cpp

HEADERS += \
    UI/mainwindow.h \
    UI/glwidget.h \
    glew-1.10.0/include/GL/glew.h \
    glData/vbo.h \
    glData/vao.h \
    Jellyfish/jellyfish.h

FORMS += \
    UI/mainwindow.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shader/shaders.qrc

DISTFILES += \
    shader/shader.vert \
    shader/shader.frag
