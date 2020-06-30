QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11

TARGET = app


HEADERS += \
    stringlistmodel.h

SOURCES += \
    main.cpp \
    stringlistmodel.cpp

DISTFILES += \
    ReadMe.md


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
