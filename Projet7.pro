QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Addition.cpp \
    Constante.cpp \
    Division.cpp \
    Expression.cpp \
    Multiplication.cpp \
    Operateur.cpp \
    Saisie.cpp \
    Soustraction.cpp \
    Variable.cpp \
    graphe.cpp \
    main.cpp

HEADERS += \
    Addition.h \
    Constante.h \
    Division.h \
    Expression.h \
    Multiplication.h \
    Operateur.h \
    Saisie.h \
    Soustraction.h \
    Variable.h \
    graphe.h

FORMS += \
    Saisie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
