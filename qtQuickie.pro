#-------------------------------------------------
#
# Project created by QtCreator 2014-09-07T14:59:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtQuickie
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qdevicewatcher.cpp \
    qdevice_watcher_linux.cpp \
    qdevice_watcher_win32.cpp \
    qdevice_watcher_wince.cpp \
    qdevicechangeevent.cpp

HEADERS  += mainwindow.h \
    qdevicewatcher.h \
    qdevicewatcher_p.h \
    qdevicewatcher_global.h \
    qdevicechangeevent.h

FORMS    += mainwindow.ui
