QT += core gui

TARGET = rapidshell-gui
TEMPLATE = lib

CONFIG += create_prl static debug_and_release build_all
CONFIG(debug, debug|release) {
    OBJECTS_DIR = debug
    DESTDIR = debug
    DEFINES += DEBUG
    #PRE_TARGETDEPS += ../Simulation/debug/libSimulation.a
} else {
    OBJECTS_DIR = release
    DESTDIR = release
    DEFINES += RELEASE
    #PRE_TARGETDEPS += ../Simulation/release/libSimulation.a
}

INCLUDEPATH += src include
MOC_DIR = tmp
UI_DIR = tmp
RCC_DIR = tmp

HEADERS += \
    include/mainwindow.h

SOURCES += \
    src/mainwindow.cpp

FORMS += \
    ui/mainwindow.ui
