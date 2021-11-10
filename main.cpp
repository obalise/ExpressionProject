#include "SaisieGraphe.h"

#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QThread>

#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FenPrincipale fenetre(900, 450);

    fenetre.show();

    return app.exec();
}

