#include "SaisieGraphe.h"

#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QThread>

#include <iostream>
#include "Addition.h"
#include "Soustraction.h"
#include "Singleton.h"
#include "Multiplication.h"
#include "Division.h"
#include "Constante.h"
#include "Expression.h"
#include "Variable.h"
#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"
#include "terminalmenu.h"
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    int mode = 1; //mode 0 : terminal, mode 1 : graphique

    if(mode == 1)
    {

        QApplication app(argc, argv);

        FenPrincipale fenetre(900, 450);

        fenetre.show();

        return app.exec();
    }
    else
    {
        TerminalMenu t_menu;
        t_menu.main_boucle();
    }

    return 0;
}

