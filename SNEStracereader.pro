#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T12:10:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SNEStracereader
TEMPLATE = app


SOURCES += main.cpp\
        wsnestracereader.cpp \
    tracehighlighter.cpp \
    disassembledialog.cpp \
    traceedit.cpp \
    calltreeitem.cpp \
    searchwindow.cpp \
    simpletracewindow.cpp

HEADERS  += wsnestracereader.h \
    tracehighlighter.h \
    disassembledialog.h \
    traceedit.h \
    callcodeobject.h \
    calltreeitem.h \
    searchwindow.h \
    simpletracewindow.h

FORMS    += wsnestracereader.ui \
    disassembledialog.ui \
    searchwindow.ui \
    simpletracewindow.ui
