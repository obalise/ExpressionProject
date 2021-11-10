#include <iostream>
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Constante.h"
#include "Expression.h"
#include "Variable.h"
#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FenPrincipale fenetre(900, 450);

    fenetre.show();

    return app.exec();
}
