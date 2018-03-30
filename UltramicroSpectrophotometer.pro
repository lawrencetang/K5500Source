#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T11:19:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32 {
    Debug:TARGET = UltramicroSpectrophotometer_d
    Release:TARGET = UltramicroSpectrophotometer
}
TEMPLATE = app

DESTDIR += ./bin
UI_DIR  = ./tmp/uic
RCC_DIR = ./tmp/rcc
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

include(oledevices/oledevices.pri)
include(oledrivers/oledrivers.pri)
include(oleplugins/oleplugins.pri)
include(oleprotocols/oleprotocols.pri)
include(applications/applications.pri)

SOURCES += main.cpp\
        ultramicrospectrophotometer.cpp

HEADERS  += ultramicrospectrophotometer.h

FORMS    += ultramicrospectrophotometer.ui

DISTFILES += \
    ./bin/configs/system.ini \
    ./bin/configs/optical.ini \
    ./bin/configs/device.ini

RC_FILE += UltramicroSpectrophotometer.rc

TRANSLATIONS += UltramicroSpectrophotometer.ts
