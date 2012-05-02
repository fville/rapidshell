QT += core gui
TARGET = rapidshell
TEMPLATE = app

CONFIG += link_prl debug_and_release build_all
CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug
    DESTDIR = debug
    DEFINES += DEBUG
    LIBS += -L../rapidshell-svn/debug
    PRE_TARGETDEPS += ../rapidshell-svn/debug/librapidshell-svn.a
    LIBS += -L../rapidshell-gui/debug
    PRE_TARGETDEPS += ../rapidshell-gui/debug/librapidshell-gui.a
} else {
    OBJECTS_DIR = release
    DESTDIR = release
    DEFINES += RELEASE
    LIBS += -L../rapidshell-svn/release
    PRE_TARGETDEPS += ../rapidshell-svn/release/librapidshell-svn.a
    LIBS += -L../rapidshell-gui/release
    PRE_TARGETDEPS += ../rapidshell-gui/release/librapidshell-gui.a
}

INCLUDEPATH += src include ../rapidshell-svn/include ../rapidshell-gui/include
MOC_DIR = tmp
UI_DIR = tmp
RCC_DIR = tmp

LIBS += -lrapidshell-svn -lrapidshell-gui

SOURCES += \
    src/main.cpp
