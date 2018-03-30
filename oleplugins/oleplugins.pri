INCLUDEPATH += $$PWD/ofileexplorer\
               $$PWD/omessagebox\
               $$PWD/orecordtablewidget\
               $$PWD/ovirtualkeyboard\
               $$PWD/omessagebox\
               $$PWD/oplot\
               $$PWD/ocomponent\
               $$PWD/singleapplication\
               $$PWD/accredit

LIBS += -L"C:\Qt\Qt5.4.2\5.4\mingw491_32\lib"-lqwt
INCLUDEPATH += "C:\Qt\Qt5.4.2\5.4\mingw491_32\include\Qwt"
include (C:\Qwt-6.1.2\features\qwt.prf)

HEADERS += \
    $$PWD/oplot/olegend.h \
    $$PWD/oplot/oplot.h \
    $$PWD/oplot/oplotcanvas.h \
    $$PWD/oplot/oplotzoomer.h \
    $$PWD/orecordtablewidget/orecordtablewidget.h \
    $$PWD/orecordtablewidget/otabelwidget.h \
    $$PWD/ovirtualkeyboard/odigitkeyboard.h \
    $$PWD/ovirtualkeyboard/ofullkeyboard.h \
    $$PWD/omessagebox/oimageview.h \
    $$PWD/omessagebox/oimageviewutil.h \
    $$PWD/omessagebox/omessagebox.h \
    $$PWD/omessagebox/omessageboxutil.h \
    $$PWD/ofileexplorer/oexplorerlistdelegate.h \
    $$PWD/ofileexplorer/oexplorerlistmodel.h \
    $$PWD/ofileexplorer/oexplorerlistview.h \
    $$PWD/ofileexplorer/ofileexplorer.h \
    $$PWD/ocomponent/ocontrolpanel.h \
    $$PWD/ocomponent/oscrollarea.h \
    $$PWD/singleapplication/singleapplication.h \
    $$PWD/omessagebox/otableview.h \
    $$PWD/omessagebox/otableviewutil.h \
    $$PWD/accredit/accredit.h \
    $$PWD/accredit/accrediti.h \
    $$PWD/accredit/aes.h \
    $$PWD/accredit/aesi.h

SOURCES += \
    $$PWD/oplot/olegend.cpp \
    $$PWD/oplot/oplot.cpp \
    $$PWD/oplot/oplotcanvas.cpp \
    $$PWD/oplot/oplotzoomer.cpp \
    $$PWD/orecordtablewidget/orecordtablewidget.cpp \
    $$PWD/orecordtablewidget/otabelwidget.cpp \
    $$PWD/ovirtualkeyboard/odigitkeyboard.cpp \
    $$PWD/ovirtualkeyboard/ofullkeyboard.cpp \
    $$PWD/omessagebox/oimageview.cpp \
    $$PWD/omessagebox/oimageviewutil.cpp \
    $$PWD/omessagebox/omessagebox.cpp \
    $$PWD/omessagebox/omessageboxutil.cpp \
    $$PWD/ofileexplorer/oexplorerlistdelegate.cpp \
    $$PWD/ofileexplorer/oexplorerlistmodel.cpp \
    $$PWD/ofileexplorer/oexplorerlistview.cpp \
    $$PWD/ofileexplorer/ofileexplorer.cpp \
    $$PWD/ocomponent/ocontrolpanel.cpp \
    $$PWD/ocomponent/oscrollarea.cpp \
    $$PWD/singleapplication/singleapplication.cpp \
    $$PWD/omessagebox/otableview.cpp \
    $$PWD/omessagebox/otableviewutil.cpp \
    $$PWD/accredit/accredit.cpp \
    $$PWD/accredit/accrediti.cpp \
    $$PWD/accredit/aes.cpp \
    $$PWD/accredit/aesi.cpp

RESOURCES += \
    $$PWD/orecordtablewidget/orecordtablewidget.qrc \
    $$PWD/ovirtualkeyboard/ofullkeyboard.qrc \
    $$PWD/omessagebox/omessagebox.qrc \
    $$PWD/ofileexplorer/ofileexplorer.qrc

FORMS += \
    $$PWD/orecordtablewidget/orecordtablewidget.ui \
    $$PWD/ovirtualkeyboard/odigitkeyboard.ui \
    $$PWD/ovirtualkeyboard/ofullkeyboard.ui \
    $$PWD/omessagebox/oimageview.ui \
    $$PWD/omessagebox/omessagebox.ui \
    $$PWD/ofileexplorer/ofileexplorer.ui \
    $$PWD/ocomponent/ocontrolpanel.ui \
    $$PWD/ocomponent/oscrollarea.ui \
    $$PWD/omessagebox/otableview.ui
