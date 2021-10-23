#include "fenprincipale.h"
#include <windows.h>
#include <stdio.h>


//FenPrincipale::FenPrincipale(QWidget *parent) : QMainWindow(parent)
FenPrincipale::FenPrincipale(int x, int y)
{

    setFixedSize(x, y);

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QMenu *menuOutils = menuBar()->addMenu("&Outils");

    QAction *actionSauvegarder = new QAction("&Sauvegarder", this);
    QAction *actionCharger = new QAction("&Charger", this);
    QAction *actionQuitter = new QAction("&Quitter", this);

    QAction *actionSaisie = new QAction("&Saisie de l'expression", this);
    QAction *actionAffichageNC = new QAction("&Affichage de l'expression en NC", this);
    QAction *actionAffichageNPI = new QAction("&Affichage de l'expression en NPI", this);
    QAction *actionAffichageVal = new QAction("&Affichage de la valeur de l'expression", this);
    QAction *actionAffichageGraph = new QAction("&Affichage graphique en 2D ", this);

    QAction *actionSimplification = new QAction("&Simplification de l'epxression", this);

     menuFichier->addAction(actionSauvegarder);
     menuFichier->addAction(actionCharger);
     menuFichier->addAction(actionQuitter);

     menuEdition->addAction(actionSaisie);
     menuEdition->addAction(actionAffichageNC);
     menuEdition->addAction(actionAffichageNPI);
     menuEdition->addAction(actionAffichageVal);
     menuEdition->addAction(actionAffichageGraph);

     menuOutils->addAction(actionSimplification);

     connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
     connect(actionSaisie, SIGNAL(triggered()), this, SLOT(saisie()));
}

void FenPrincipale::saisie()
{
    // detach from the current console window
    // if launched from a console window, that will still run waiting for the new console (below) to close
    // it is useful to detach from Qt Creator's <Application output> panel
    FreeConsole();

    // create a separate new console window
    AllocConsole();

    // attach the new console to this application's process
    AttachConsole(GetCurrentProcessId());

    // reopen the std I/O streams to redirect I/O to the new console
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);

    QWidget w;

    puts("Saisissez l'expression:");
    getchar();
    w.show();


}
