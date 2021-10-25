#include <vector>
#include <sstream>

#include "fenprincipale.h"
#include "Constante.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Expression.h"
#include "Constante.h"



//#define DEBUG

#ifdef DEBUG
#include <windows.h>
#include <stdio.h>
#endif

#include <QtWidgets>

using namespace std;

FenPrincipale::FenPrincipale(int x, int y)
{

    setFixedSize(x, y);

    fileName = new QString();
    textEdit = new QTextEdit(this);

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

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

     connect(actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarder()));
     connect(actionCharger, SIGNAL(triggered()), this, SLOT(charger()));
     connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

     connect(actionSaisie, SIGNAL(triggered()), this, SLOT(saisie()));
     connect(actionAffichageNC, SIGNAL(triggered()), this, SLOT(affichageNC()));
}

void FenPrincipale::saisie()
{

    /* Le groupe 8 doit fournir à l’aide du « design pattern » singleton un accès simplifié à l’expression gérée par le programme. */
    /* Utiliser et Appeler par ex. la sauvegarde de l'expression lorsque l'entrée du menu correspondante est sélectionnée.*/

#ifdef DEBUG
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
#endif


}

bool FenPrincipale::sauvegarder()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);

}

bool FenPrincipale::saveFile(const QString &fileName)
{
    QString errorMessage;

    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QSaveFile file(fileName);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << textEdit->toPlainText();
        if (!file.commit()) {
            errorMessage = tr("Cannot write file %1:\n%2.")
                           .arg(QDir::toNativeSeparators(fileName), file.errorString());
        }
    } else {
        errorMessage = tr("Cannot open file %1 for writing:\n%2.")
                       .arg(QDir::toNativeSeparators(fileName), file.errorString());
    }
    QGuiApplication::restoreOverrideCursor();

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, tr("SDI"), errorMessage);
        return false;
    }

    //setCurrentFile(fileName);
    //statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void FenPrincipale::charger()
{

    *fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier textes (*.txt)");
    //QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + *fileName);


    QFile file(*fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Projet6"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(*fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QGuiApplication::restoreOverrideCursor();

    //setCurrentFile(*fileName);
    //statusBar()->showMessage(tr("File loaded"), 2000);

}

void FenPrincipale::affichageNC()
{

    bool ok;
    int i(0);
    vector<Constante> tab(2, 0);
    vector<Constante> tabDyn; //Crée un tableau dynamique de x nombre à virgule

    QString op, test;
    stringstream out;

    QFile fichier(*fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    while(! flux.atEnd())
    {
        flux >> mot;

        float flo = mot.toFloat(&ok);
        if(ok)
        {
            Constante c1(flo);
            cout << c1 << endl;

            tab[i] = flo;
            cout << tab[i] << endl;

            tabDyn.push_back(flo);
            cout << tabDyn[i] << endl;

            i++;
        }
        else
        {
            op = mot;
        }
    }

    if (op == '+')
    {
        //Création d'une addition
        Addition add1(&tab[0], &tab[1]);

        cout << add1 << endl;

        out << add1;
        test = QString::fromStdString(out.str());
        textEdit->setPlainText(test);

    }
    else if (op == '-')
    {
        cout << "Soustraction" << endl;
    }
    else if (op == '*')
    {
        cout << "Multiplication" << endl;
    }
    else
    {
        cout << "Division" << endl;
    }


}
