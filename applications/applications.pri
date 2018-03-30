INCLUDEPATH += $$PWD/models\
               $$PWD/nucleicacidwindow\
               $$PWD/nucleicacidwindow/models\
               $$PWD/nucleicacidwindow/background\
               $$PWD/proteinwindow\
               $$PWD/proteinwindow/models\
               $$PWD/proteinwindow/background\
               $$PWD/uvviswindow\
               $$PWD/uvviswindow/models\
               $$PWD/uvviswindow/background\
               $$PWD/cellculturewindow\
               $$PWD/cellculturewindow/models\
               $$PWD/cellculturewindow/background\
               $$PWD/nanogoldwindow\
               $$PWD/nanogoldwindow/models\
               $$PWD/nanogoldwindow/background\
               $$PWD/microarraywindow\
               $$PWD/microarraywindow/models\
               $$PWD/microarraywindow/background\
               $$PWD/dynamicswindow\
               $$PWD/dynamicswindow/models\
               $$PWD/dynamicswindow/background\
               $$PWD/kitmethodwindow\
               $$PWD/kitmethodwindow/models\
               $$PWD/kitmethodwindow/background\
               $$PWD/devicecheckwindow\
               $$PWD/temperaturewindow\
               $$PWD/toolwindow\
               $$PWD/oligocalculator


RESOURCES += \
    $$PWD/nucleicacidwindow/nucleicacidwindow.qrc \
    $$PWD/proteinwindow/proteinwindow.qrc \
    $$PWD/uvviswindow/uvviswindow.qrc \
    $$PWD/cellculturewindow/cellculturewindow.qrc \
    $$PWD/nanogoldwindow/nanogoldwindow.qrc \
    $$PWD/microarraywindow/microarraywindow.qrc \
    $$PWD/dynamicswindow/dynamicswindow.qrc \
    $$PWD/kitmethodwindow/kitmethodwindow.qrc \
    $$PWD/devicecheckwindow/devicecheckwindow.qrc \
    $$PWD/toolwindow/toolwindow.qrc \
    $$PWD/temperaturewindow/temperaturewindow.qrc

FORMS += \
    $$PWD/nucleicacidwindow/nucleicacidwindow.ui \
    $$PWD/proteinwindow/proteinwindow.ui \
    $$PWD/nucleicacidwindow/natestingwidget.ui \
    $$PWD/nucleicacidwindow/nasettingwidget.ui \
    $$PWD/nucleicacidwindow/naparameterwidget.ui \
    $$PWD/proteinwindow/pttestingwidget.ui \
    $$PWD/proteinwindow/ptparameterwidget.ui \
    $$PWD/proteinwindow/ptsettingwidget.ui \
    $$PWD/uvviswindow/uvviswindow.ui \
    $$PWD/uvviswindow/uvtestingwidget.ui \
    $$PWD/uvviswindow/uvsettingwidget.ui \
    $$PWD/uvviswindow/uvparameterwidget.ui \
    $$PWD/cellculturewindow/cellculturewindow.ui \
    $$PWD/cellculturewindow/ccparameterwidget.ui \
    $$PWD/cellculturewindow/ccsettingwidget.ui \
    $$PWD/cellculturewindow/cctestingwidget.ui \
    $$PWD/nanogoldwindow/nanogoldwindow.ui \
    $$PWD/nanogoldwindow/ngtestingwidget.ui \
    $$PWD/nanogoldwindow/ngparameterwidget.ui \
    $$PWD/nanogoldwindow/ngsettingwidget.ui \
    $$PWD/microarraywindow/microarraywindow.ui \
    $$PWD/microarraywindow/matestingwidget.ui \
    $$PWD/microarraywindow/masettingwidget.ui \
    $$PWD/microarraywindow/maparameterwidget.ui \
    $$PWD/microarraywindow/madyewidget.ui \
    $$PWD/dynamicswindow/dynamicswindow.ui \
    $$PWD/dynamicswindow/dytestingwidget.ui \
    $$PWD/dynamicswindow/dysettingwidget.ui \
    $$PWD/dynamicswindow/dyparameterwidget.ui \
    $$PWD/kitmethodwindow/kitmethodwindow.ui \
    $$PWD/kitmethodwindow/kmtestingwidget.ui \
    $$PWD/kitmethodwindow/kmparameterwidget.ui \
    $$PWD/kitmethodwindow/kmsettingwidget.ui \
    $$PWD/kitmethodwindow/kmfittingwidget.ui \
    $$PWD/devicecheckwindow/devicecheckwindow.ui \
    $$PWD/temperaturewindow/temperaturewindow.ui \
    $$PWD/toolwindow/toolwindow.ui \
    $$PWD/oligocalculator/oligocalculator.ui

HEADERS += \
    $$PWD/nucleicacidwindow/nucleicacidwindow.h \
    $$PWD/models/microscaleopticalmodel.h \
    $$PWD/models/cuvetteopticalmodel.h \
    $$PWD/proteinwindow/proteinwindow.h \
    $$PWD/nucleicacidwindow/natestingwidget.h \
    $$PWD/nucleicacidwindow/nasettingwidget.h \
    $$PWD/nucleicacidwindow/naparameterwidget.h \
    $$PWD/nucleicacidwindow/models/nasettingmodel.h \
    $$PWD/nucleicacidwindow/background/nadetectionflow.h \
    $$PWD/proteinwindow/pttestingwidget.h \
    $$PWD/proteinwindow/ptsettingwidget.h \
    $$PWD/proteinwindow/ptparameterwidget.h \
    $$PWD/proteinwindow/models/ptsettingmodel.h \
    $$PWD/proteinwindow/background/ptdetectionflow.h \
    $$PWD/uvviswindow/uvviswindow.h \
    $$PWD/uvviswindow/uvtestingwidget.h \
    $$PWD/uvviswindow/uvsettingwidget.h \
    $$PWD/uvviswindow/uvparameterwidget.h \
    $$PWD/uvviswindow/models/uvsettingmodel.h \
    $$PWD/uvviswindow/background/uvdetectionflow.h \
    $$PWD/cellculturewindow/cellculturewindow.h \
    $$PWD/cellculturewindow/cctestingwidget.h \
    $$PWD/cellculturewindow/ccparameterwidget.h \
    $$PWD/cellculturewindow/ccsettingwidget.h \
    $$PWD/cellculturewindow/models/ccsettingmodel.h \
    $$PWD/cellculturewindow/background/ccdetectionflow.h \
    $$PWD/nanogoldwindow/nanogoldwindow.h \
    $$PWD/nanogoldwindow/ngtestingwidget.h \
    $$PWD/nanogoldwindow/ngsettingwidget.h \
    $$PWD/nanogoldwindow/ngparameterwidget.h \
    $$PWD/nanogoldwindow/models/ngsettingmodel.h \
    $$PWD/nanogoldwindow/background/ngdetectionflow.h \
    $$PWD/microarraywindow/microarraywindow.h \
    $$PWD/microarraywindow/matestingwidget.h \
    $$PWD/microarraywindow/masettingwidget.h \
    $$PWD/microarraywindow/maparameterwidget.h \
    $$PWD/microarraywindow/models/masettingmodel.h \
    $$PWD/microarraywindow/background/madetectionflow.h \
    $$PWD/microarraywindow/madyewidget.h \
    $$PWD/microarraywindow/madyetablewidget.h \
    $$PWD/dynamicswindow/dynamicswindow.h \
    $$PWD/dynamicswindow/dytestingwidget.h \
    $$PWD/dynamicswindow/dysettingwidget.h \
    $$PWD/dynamicswindow/dyparameterwidget.h \
    $$PWD/dynamicswindow/models/dysettingmodel.h \
    $$PWD/dynamicswindow/background/dydetectionflow.h \
    $$PWD/kitmethodwindow/kitmethodwindow.h \
    $$PWD/kitmethodwindow/kmtestingwidget.h \
    $$PWD/kitmethodwindow/kmparameterwidget.h \
    $$PWD/kitmethodwindow/kmsettingwidget.h \
    $$PWD/kitmethodwindow/models/kmsettingmodel.h \
    $$PWD/kitmethodwindow/background/kmdetectionflow.h \
    $$PWD/kitmethodwindow/kmfittingwidget.h \
    $$PWD/kitmethodwindow/kmtablewidget.h \
    $$PWD/kitmethodwindow/models/kmolsfit.h \
    $$PWD/devicecheckwindow/devicecheckwindow.h \
    $$PWD/temperaturewindow/temperaturewindow.h \
    $$PWD/toolwindow/toolwindow.h \
    $$PWD/temperaturewindow/cqdial.h \
    $$PWD/oligocalculator/oligocalculator.h

SOURCES += \
    $$PWD/nucleicacidwindow/nucleicacidwindow.cpp \
    $$PWD/models/microscaleopticalmodel.cpp \
    $$PWD/models/cuvetteopticalmodel.cpp \
    $$PWD/proteinwindow/proteinwindow.cpp \
    $$PWD/nucleicacidwindow/natestingwidget.cpp \
    $$PWD/nucleicacidwindow/nasettingwidget.cpp \
    $$PWD/nucleicacidwindow/naparameterwidget.cpp \
    $$PWD/nucleicacidwindow/models/nasettingmodel.cpp \
    $$PWD/nucleicacidwindow/background/nadetectionflow.cpp \
    $$PWD/proteinwindow/pttestingwidget.cpp \
    $$PWD/proteinwindow/ptsettingwidget.cpp \
    $$PWD/proteinwindow/ptparameterwidget.cpp \
    $$PWD/proteinwindow/models/ptsettingmodel.cpp \
    $$PWD/proteinwindow/background/ptdetectionflow.cpp \
    $$PWD/uvviswindow/uvviswindow.cpp \
    $$PWD/uvviswindow/uvtestingwidget.cpp \
    $$PWD/uvviswindow/uvsettingwidget.cpp \
    $$PWD/uvviswindow/uvparameterwidget.cpp \
    $$PWD/uvviswindow/models/uvsettingmodel.cpp \
    $$PWD/uvviswindow/background/uvdetectionflow.cpp \
    $$PWD/cellculturewindow/cellculturewindow.cpp \
    $$PWD/cellculturewindow/ccparameterwidget.cpp \
    $$PWD/cellculturewindow/ccsettingwidget.cpp \
    $$PWD/cellculturewindow/cctestingwidget.cpp \
    $$PWD/cellculturewindow/models/ccsettingmodel.cpp \
    $$PWD/cellculturewindow/background/ccdetectionflow.cpp \
    $$PWD/nanogoldwindow/nanogoldwindow.cpp \
    $$PWD/nanogoldwindow/ngtestingwidget.cpp \
    $$PWD/nanogoldwindow/ngsettingwidget.cpp \
    $$PWD/nanogoldwindow/ngparameterwidget.cpp \
    $$PWD/nanogoldwindow/models/ngsettingmodel.cpp \
    $$PWD/nanogoldwindow/background/ngdetectionflow.cpp \
    $$PWD/microarraywindow/microarraywindow.cpp \
    $$PWD/microarraywindow/matestingwidget.cpp \
    $$PWD/microarraywindow/masettingwidget.cpp \
    $$PWD/microarraywindow/maparameterwidget.cpp \
    $$PWD/microarraywindow/models/masettingmodel.cpp \
    $$PWD/microarraywindow/background/madetectionflow.cpp \
    $$PWD/microarraywindow/madyewidget.cpp \
    $$PWD/microarraywindow/madyetablewidget.cpp \
    $$PWD/dynamicswindow/dynamicswindow.cpp \
    $$PWD/dynamicswindow/dytestingwidget.cpp \
    $$PWD/dynamicswindow/dysettingwidget.cpp \
    $$PWD/dynamicswindow/dyparameterwidget.cpp \
    $$PWD/dynamicswindow/models/dysettingmodel.cpp \
    $$PWD/dynamicswindow/background/dydetectionflow.cpp \
    $$PWD/kitmethodwindow/kitmethodwindow.cpp \
    $$PWD/kitmethodwindow/kmtestingwidget.cpp \
    $$PWD/kitmethodwindow/kmparameterwidget.cpp \
    $$PWD/kitmethodwindow/kmsettingwidget.cpp \
    $$PWD/kitmethodwindow/models/kmsettingmodel.cpp \
    $$PWD/kitmethodwindow/background/kmdetectionflow.cpp \
    $$PWD/kitmethodwindow/kmfittingwidget.cpp \
    $$PWD/kitmethodwindow/kmtablewidget.cpp \
    $$PWD/kitmethodwindow/models/kmolsfit.cpp \
    $$PWD/devicecheckwindow/devicecheckwindow.cpp \
    $$PWD/temperaturewindow/temperaturewindow.cpp \
    $$PWD/toolwindow/toolwindow.cpp \
    $$PWD/temperaturewindow/cqdial.cpp \
    $$PWD/oligocalculator/oligocalculator.cpp

DISTFILES += \
    $$PWD/bin/configs/nucleicacid/nucleicacid.ini \
    $$PWD/bin/configs/protein/protein.ini \
    $$PWD/bin/configs/uv_vis/uv_vis.ini \
    $$PWD/bin/configs/cellculture/cellculture.ini \
    $$PWD/bin/configs/nanogold/nanogold.ini \
    $$PWD/bin/configs/microarray/microarray.ini \
    $$PWD/bin/configs/dynamics/dynamics.ini \
    $$PWD/bin/configs/kitmethod/kitmethod.ini \
    $$PWD/bin/configs/devicecheck/devicecheck.ini \
    $$PWD/bin/images/新建文件夹/1063344.png \
    $$PWD/bin/images/新建文件夹/1063107.png
