#include "SaisieGraphe.h"

#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QThread>

#include <iostream>
#include <sstream>
#include <string>

#include "Graphe.h"
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
    QApplication a(argc, argv);
    Saisie w;
    w.show();
    return a.exec();

    return 0;
}

