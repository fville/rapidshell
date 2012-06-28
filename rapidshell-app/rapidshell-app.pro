QT += core gui
TARGET = rapidshell
TEMPLATE = app

CONFIG += link_prl debug_and_release build_all
CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug
    DESTDIR = debug
    DEFINES += DEBUG
    LIBS += -L../rapidshell-svn/debug
    unix:PRE_TARGETDEPS += ../rapidshell-svn/debug/librapidshell-svn.a
    win32:PRE_TARGETDEPS += ../rapidshell-svn/debug/rapidshell-svn.lib
    LIBS += -L../rapidshell-gui/debug
    unix:PRE_TARGETDEPS += ../rapidshell-gui/debug/librapidshell-gui.a
    win32:PRE_TARGETDEPS += ../rapidshell-gui/debug/rapidshell-gui.lib
} else {
    OBJECTS_DIR = release
    DESTDIR = release
    DEFINES += RELEASE
    LIBS += -L../rapidshell-svn/release
    unix:PRE_TARGETDEPS += ../rapidshell-svn/release/librapidshell-svn.a
    win32:PRE_TARGETDEPS += ../rapidshell-svn/release/rapidshell-svn.lib
    LIBS += -L../rapidshell-gui/release
    unix:PRE_TARGETDEPS += ../rapidshell-gui/release/librapidshell-gui.a
    win32:PRE_TARGETDEPS += ../rapidshell-gui/release/rapidshell-gui.lib
}

INCLUDEPATH += src include ../rapidshell-svn/include ../rapidshell-gui/include
MOC_DIR = tmp
UI_DIR = tmp
RCC_DIR = tmp

LIBS += -lrapidshell-svn -lrapidshell-gui

SOURCES += \
    src/main.cpp
