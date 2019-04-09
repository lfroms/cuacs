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
        Components/MainWindow.cc \
    Repository/DatabaseAdapter/DatabaseAdapter.cc \
    main.cc \
    Repository/Client/Client.cc \
    Repository/DatabaseAdapter/Seeds.cc \
    Components/Animals/AnimalDetailsModal.cc \
    Repository/Animal/Animal.cc \
    Components/DetailListWidgetItem.cc \
    Components/Clients/ClientDetailsModal.cc \
    Repository/Attribute/Attribute.cc \
    Repository/User/User.cc \
    Authentication/LoginWindow.cc \
    Repository/Session/Session.cc \
    Components/ACM/Match.cc \
    Components/ACM/MatchCreator.cc \
    Components/ACM/CompatibilityScorer.cc \
    Components/ACMResultListWidgetItem.cc \
    Components/StyleUtil.cc \
    Components/ACM/MatchDetailsModal.cc

HEADERS += \
        Components/MainWindow.h \
    Repository/DatabaseAdapter/DatabaseAdapter.h \
    Repository/Client/Client.h \
    Repository/DatabaseAdapter/Seeds.h \
    Components/Animals/AnimalDetailsModal.h \
    Repository/Animal/Animal.h \
    Components/DetailListWidgetItem.h \
    Components/Clients/ClientDetailsModal.h \
    Repository/DatabaseAdapter/Schema.h \
    Repository/DatabaseAdapter/Config.h \
    Repository/ActiveObject/ActiveObject.h \
    Repository/Attribute/Attribute.h \
    Repository/ActiveObject/AttributedObject.h \
    Repository/User/User.h \
    Authentication/LoginWindow.h \
    Repository/Session/Session.h \
    Components/ACM/Match.h \
    Components/ACM/MatchCreator.h \
    Components/ACM/CompatibilityScorer.h \
    Components/ACMResultListWidgetItem.h \
    Components/StyleUtil.h \
    Components/ACM/MatchDetailsModal.h

FORMS += \
        Components/MainWindow.ui \
    Components/Animals/AnimalDetailsModal.ui \
    Components/DetailListWidgetItem.ui \
    Components/Clients/ClientDetailsModal.ui \
    Authentication/LoginWindow.ui \
    Components/ACMResultListWidgetItem.ui \
    Components/ACM/MatchDetailsModal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Resources/styles.txt

# Copy the stylesheet into the build folder
QMAKE_POST_LINK += cp $$PWD/Resources/styles.txt $$OUT_PWD
