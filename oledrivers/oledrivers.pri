INCLUDEPATH += $$PWD/ousb
LIBS += $$PWD/ousb/libusb.a

HEADERS += \
    $$PWD/ousb/lusb0_usb.h \
    $$PWD/ousb/ousb.h

SOURCES += \
    $$PWD/ousb/ousb.cpp
