INCLUDEPATH += $$PWD/oserialport\
               $$PWD/ospectrograph
QT += serialport

HEADERS += \
    $$PWD/oserialport/oserialport.h \
    $$PWD/ospectrograph/absorbance.h \
    $$PWD/ospectrograph/opticalintensity.h \
    $$PWD/ospectrograph/ospectrograph.h \
    $$PWD/ospectrograph/ospectrographdevice.h


SOURCES += \
    $$PWD/oserialport/oserialport.cpp \
    $$PWD/ospectrograph/absorbance.cpp \
    $$PWD/ospectrograph/opticalintensity.cpp \
    $$PWD/ospectrograph/ospectrograph.cpp \
    $$PWD/ospectrograph/ospectrographdevice.cpp

