QT += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    Saisie.cpp \
    Simplifier.cpp \
    Singleton.cpp \
    fenetregraphe.cpp \
    fenprincipale.cpp \
    Addition.cpp \
    Constante.cpp \
    Division.cpp \
    Expression.cpp \
    Multiplication.cpp \
    Operateur.cpp \
    SaisieGraphe.cpp \
    Soustraction.cpp \
    Variable.cpp \
    graphe.cpp \
    saisieexpressiongraphe.cpp \
    terminalmenu.cpp \
    main.cpp
HEADERS += \
    Saisie.h \
    Simplifier.h \
    Singleton.h \
    fenetregraphe.h \
    fenprincipale.h \
    Addition.h \
    Constante.h \
    Division.h \
    Expression.h \
    Multiplication.h \
    Operateur.h \
    SaisieGraphe.h \
    Soustraction.h \
    graphe.h \
    saisieexpressiongraphe.h \
    terminalmenu.h \
    Variable.h
FORMS += \
    FenetreGraphe.ui \
    SaisieGraphe.ui \
    saisieexpressiongraphe.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
