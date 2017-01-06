#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T12:10:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$IN_PWD

TARGET = SNEStracereader
TEMPLATE = app


SOURCES += main.cpp\
        wsnestracereader.cpp \
    tracehighlighter.cpp \
    disassembledialog.cpp \
    calltreeitem.cpp \
    searchwindow.cpp \
    simpletracewindow.cpp \
    routinemapeditor.cpp \
    routinemapfile.cpp \
    snestracetextedit.cpp \
    traceeditsidebar.cpp \
    readwritewindow.cpp \
    disassemblylaunchwindow.cpp \
    disassemblywindow.cpp \
    asmsyntaxhl.cpp \
    correctedscrolltreeview.cpp

HEADERS  += wsnestracereader.h \
    tracehighlighter.h \
    disassembledialog.h \
    callcodeobject.h \
    calltreeitem.h \
    searchwindow.h \
    simpletracewindow.h \
    stuffreadwrite.h \
    routinemapeditor.h \
    routinemapfile.h \
    snestracetextedit.h \
    traceeditsidebar.h \
    readwritewindow.h \
    disassemblylaunchwindow.h \
    disassemblywindow.h \
    asmsyntaxhl.h \
    correctedscrolltreeview.h

FORMS    += wsnestracereader.ui \
    disassembledialog.ui \
    searchwindow.ui \
    simpletracewindow.ui \
    routinemapeditor.ui \
    readwritewindow.ui \
    disassemblylaunchwindow.ui \
    disassemblywindow.ui


RC_FILE = SNESTracereader.rc

DISTFILES +=

SUBDIRS += \
    dispelgui.pro

