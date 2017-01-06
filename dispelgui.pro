QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$IN_PWD

TARGET = DispelUi
TEMPLATE = app

SOURCES += dispeluimain.cpp \
    asmsyntaxhl.cpp \
    disassemblylaunchwindow.cpp \
    disassemblywindow.cpp \
    dispeluimain.cpp

FORMS += \
    disassemblylaunchwindow.ui \
    disassemblywindow.ui

HEADERS += \
    asmsyntaxhl.h \
    disassemblylaunchwindow.h \
    disassemblywindow.h
