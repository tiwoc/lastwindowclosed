CONFIG += c++11
QT += core gui qml quick widgets

TARGET = lastwindowclosed
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += mainwindow.h
FORMS += mainwindow.ui

RESOURCES += \
    main.qrc

DISTFILES += \
    main.qml
