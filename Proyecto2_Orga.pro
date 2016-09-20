#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T07:41:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2_Orga
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    btreenode.cpp \
    btree.cpp

HEADERS  += mainwindow.h \
    btreenode.h \
    btree.h

FORMS    += mainwindow.ui \
    AVL_ADD.ui \
    AVL_DELETE.ui \
    AVL_SEARCH.ui
