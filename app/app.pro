#-------------------------------------------------
#
# Project created by QtCreator 2019-02-06T21:18:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        MainWindow/MainWindow.cc \
    DatabaseAdapter/DatabaseAdapter.cc \
    main.cc \
    Models/Client/Client.cc \
    DatabaseAdapter/Seeds.cc \
    MainWindow/AnimalDetailsModal.cc \
    Models/Animal/Animal.cc \
    MainWindow/DetailListWidgetItem.cc \
    MainWindow/ClientDetailsModal.cc \
    Models/Attribute/Attribute.cc

HEADERS += \
        MainWindow/MainWindow.h \
    DatabaseAdapter/DatabaseAdapter.h \
    Models/Client/Client.h \
    DatabaseAdapter/Seeds.h \
    MainWindow/AnimalDetailsModal.h \
    Models/Animal/Animal.h \
    MainWindow/DetailListWidgetItem.h \
    MainWindow/ClientDetailsModal.h \
    DatabaseAdapter/Schema.h \
    DatabaseAdapter/Config.h \
    ActiveObject/ActiveObject.h \
    Models/Attribute/Attribute.h \
    ActiveObject/AttributedObject.h

FORMS += \
        MainWindow/MainWindow.ui \
    MainWindow/AnimalDetailsModal.ui \
    MainWindow/DetailListWidgetItem.ui \
    MainWindow/ClientDetailsModal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
