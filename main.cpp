#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    FenPrincipale fenetre(600, 300);
    fenetre.show();

    return app.exec();
}
