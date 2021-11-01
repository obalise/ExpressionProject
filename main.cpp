#include "mainwindow.h"

#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <iostream>

#include "graphe.h"
#include "Expression.h"
#include "Constante.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Constante.h"
#include "Variable.h"

QT_CHARTS_USE_NAMESPACE

using namespace std;


int main(int argc, char *argv[])
{

    //Faire une fonction d'entrer de l'expression -> ITERATION2 avec Groupe 1

    //********************

    Constante florentc1(1);
    Constante florentc2(2);
    Addition florentadd1(&florentc1, &florentc2);

    Variable florentv1('y');
    Multiplication mult1(&florentadd1, &florentv1);

    Constante florentc3(8);
    Division div1(&mult1, &florentc3);

    Variable florentv2('y');
    Multiplication mult2(&div1, &florentv2);

    Graphe arnaud(0, 45, 0.5);

    arnaud.calculerPointsGraphe(&mult2);
    arnaud.tracerGraphe(argc, argv);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}

