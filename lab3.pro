#-------------------------------------------------
#
# Project created by QtCreator 2020-02-21T15:35:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
TEMPLATE = app


SOURCES += main.cpp\
        ../2lb/application.cpp \
        ../2lb/complex.cpp \
        ../2lb/main.cpp \
        ../2lb/polinom.cpp \
        application.cpp \
        complex.cpp \
        polinom.cpp \
        widget.cpp

HEADERS  += widget.h \
    ../2lb/application.h \
    ../2lb/complex.h \
    ../2lb/number.h \
    ../2lb/polinom.h \
    application.h \
    complex.h \
    number.h \
    polinom.h
