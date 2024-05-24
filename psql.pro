QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = psql
TEMPLATE = app

SOURCES += main.cpp \
           loginwindow.cpp

HEADERS += loginwindow.h

FORMS += loginwindow.ui
