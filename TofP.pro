#-------------------------------------------------
#
# Project created by QtCreator 2011-10-26T15:40:47
#
#-------------------------------------------------

QT       += core gui sql

TARGET = TofP
TEMPLATE = app

CONFIG += warn_on


SOURCES += main.cpp\
        mainwindow.cpp \
    loginform.cpp \
    userform.cpp \
    transportmanagerform.cpp \
    productmanagerform.cpp \
    tofpapplication.cpp \
    basewidget.cpp \
    catalogeditor.cpp \
    utils.cpp \
    editcatalogdialog.cpp

HEADERS  += mainwindow.h \
    loginform.h \
    userform.h \
    transportmanagerform.h \
    productmanagerform.h \
    tofpapplication.h \
    basewidget.h \
    roles.h \
    catalogeditor.h \
    utils.h \
    editcatalogdialog.h

FORMS    += mainwindow.ui \
    loginform.ui \
    userform.ui \
    transportmanagerform.ui \
    productmanagerform.ui \
    createcatalogdialog.ui \
    catalogeditor.ui \
    editcatalogdialog.ui

OTHER_FILES += \
    config.ini

RESOURCES += \
    res.qrc
