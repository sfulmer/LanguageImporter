QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App.cpp \
    ButtonPanel.cpp \
    Controller.cpp \
    DBPathObserver.cpp \
    DataTableModel.cpp \
    Language.cpp \
    LanguageObserver.cpp \
    MainPanel.cpp \
    Model.cpp \
    ModelConfig.cpp \
    ModelConfigSource.cpp \
    ModelConfigSourceDatabase.cpp \
    ModelConfigSourceNull.cpp \
    ModelConfigSourceText.cpp \
    ModelConfigSourceURL.cpp \
    ModelSourceConfigEndingObserver.cpp \
    ModelSourceConfigOpeningObserver.cpp \
    ModelSourceConfigURLObserver.cpp \
    Observable.cpp \
    SourceConfigButtonPanel.cpp \
    SourceConfigDialog.cpp \
    SourceConfigPanel.cpp \
    SourceConfigPanelURL.cpp \
    URLSourceObserver.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    App.h \
    ButtonPanel.h \
    Controller.h \
    DBPathObserver.h \
    DataTableModel.h \
    Language.h \
    LanguageObserver.h \
    MainPanel.h \
    MainWindow.h \
    Model.h \
    ModelConfig.h \
    ModelConfigSource.h \
    ModelConfigSourceDatabase.h \
    ModelConfigSourceNull.h \
    ModelConfigSourceText.h \
    ModelConfigSourceURL.h \
    ModelSourceConfigEndingObserver.h \
    ModelSourceConfigOpeningObserver.h \
    ModelSourceConfigURLObserver.h \
    Observable.h \
    SourceConfigButtonPanel.h \
    SourceConfigDialog.h \
    SourceConfigPanel.h \
    SourceConfigPanelURL.h \
    URLSourceObserver.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
