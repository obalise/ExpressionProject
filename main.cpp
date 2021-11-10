#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenprincipale.h"
#include "terminalmenu.h"


int main(int argc, char *argv[])
{

    int mode = 0; //mode 0 : terminal, mode 1 : graphique

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
}
