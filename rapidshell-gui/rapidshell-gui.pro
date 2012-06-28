QT += core gui

TARGET = rapidshell-gui
TEMPLATE = lib

CONFIG += create_prl static debug_and_release build_all
CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug
    DESTDIR = debug
    DEFINES += DEBUG
    LIBS += -L../rapidshell-svn/debug
    unix:PRE_TARGETDEPS += ../rapidshell-svn/debug/librapidshell-svn.a
    win32:PRE_TARGETDEPS += ../rapidshell-svn/debug/rapidshell-svn.lib
} else {
    OBJECTS_DIR = release
    DESTDIR = release
    DEFINES += RELEASE
    LIBS += -L../rapidshell-svn/release
    unix:PRE_TARGETDEPS += ../rapidshell-svn/release/librapidshell-svn.a
    win32:PRE_TARGETDEPS += ../rapidshell-svn/release/rapidshell-svn.lib
}

INCLUDEPATH += src include ../rapidshell-svn/include
MOC_DIR = tmp
UI_DIR = tmp
RCC_DIR = tmp

LIBS += -lrapidshell-svn

HEADERS += \
    include/mainwindow.h \
    include/openlocationdialog.h

SOURCES += \
    src/mainwindow.cpp \
    src/openlocationdialog.cpp

FORMS += \
    ui/mainwindow.ui \
    ui/openlocationdialog.ui
