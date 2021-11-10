#include <vector>
#include <sstream>
#include <string>
#include <iostream>

#include "fenprincipale.h"
#include "Constante.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Expression.h"
#include "Constante.h"
#include "SaisieGraphe.h"


//#define DEBUG

#ifdef DEBUG
#include <windows.h>
#include <stdio.h>
#endif

#include <QtWidgets>


SaisieGraphe *saisieGraphe = 0;


using namespace std;

FenPrincipale::FenPrincipale(int x, int y)
{

    setFixedSize(x, y);

    fileName = new QString();
    textEdit = new QTextEdit(this);

    QPixmap bkgnd("Images/icone.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


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
     connect(actionAffichageNPI, SIGNAL(triggered()), this, SLOT(affichageNPI()));
     connect(actionAffichageVal, SIGNAL(triggered()), this, SLOT(affichageVal()));
     connect(actionAffichageGraph, SIGNAL(triggered()), this, SLOT(affichageGraph()));

     connect(actionSimplification, SIGNAL(triggered()), this, SLOT(affichageSimplification()));

}

void FenPrincipale::saisie()
{

    /* Le groupe 8 doit fournir à l’aide du « design pattern » singleton un accès simplifié à l’expression gérée par le programme. */
    /* Utiliser et Appeler par ex. la sauvegarde de l'expression lorsque l'entrée du menu correspondante est sélectionnée.*/

    QString op, test;
    ostringstream out;

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    out << "Design pattern - singleton non disponible" << endl;

    test = QString::fromStdString(out.str());
    textEdit->setPlainText(test);


#ifdef DEBUG

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

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

    return true;
}

void FenPrincipale::charger()
{

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    *fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier textes (*.txt)");


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

}

void FenPrincipale::affichageNC()
{
    bool ok;
    int i(0);
    vector<Constante> tab(10,0);

    QString op, test;
    ostringstream out;

    QFile fichier(*fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    while(! flux.atEnd())
    {
        flux >> mot;

        float flo = mot.toFloat(&ok);

        if(ok)
        {
            tab[i] = flo;
            i++;
        }
        else
        {
           if (mot == "+" || mot == "-" || mot == "*" || mot == "/")
           op = mot;
        }

        if (op == '+' && i > 1)
        {
            //Création d'une addition
            Addition add1(&tab[0], &tab[1]);

            out << "Affichage NC addition" << endl<< add1;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '-' && i > 1)
        {
            //Création d'une soustraction
            Soustraction sous1(&tab[0], &tab[1]);

            out << "Affichage NC soustraction" << endl<< sous1;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '*' && i > 1)
        {
            //Création d'une multiplication
            Multiplication mux1(&tab[0], &tab[1]);

            out << "Affichage NC multiplication" << endl<< mux1;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '/' && i > 1)
        {
            //Création d'une division
            Division div1(&tab[0], &tab[1]);

            out << "Affichage NC division" << endl<< div1;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else
        {
           cout << "N/A" << endl;
        }
    }
}

void FenPrincipale::affichageNPI()
{

    bool ok;
    int i(0);
    vector<Constante> tab(2, 0);

    QString op, test;
    ostringstream out;

    QFile fichier(*fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    while(! flux.atEnd())
    {
        flux >> mot;

        float flo = mot.toFloat(&ok);
        if(ok)
        {
            tab[i] = flo;
            cout << tab[i] << endl;
            i++;
        }
        else
        {
            if (mot == "+" || mot == "-" || mot == "*" || mot == "/")
            op = mot;
        }

        if (op == '+' && i > 1)
        {
            //Création d'une addition
            Addition add1(&tab[0], &tab[1]);

            add1.afficherNPI(out <<"Affichage NPI addition"<< endl);

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '-' && i > 1)
        {
            //Création d'une soustraction
            Soustraction sous1(&tab[0], &tab[1]);

            sous1.afficherNPI(out <<"Affichage NPI soustraction"<< endl);

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '*' && i > 1)
        {
            //Création d'une multiplication
            Multiplication mux1(&tab[0], &tab[1]);

            mux1.afficherNPI(out <<"Affichage NPI multiplication"<< endl);

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '/' && i > 1)
        {
            //Création d'une division
            Division div1(&tab[0], &tab[1]);

            div1.afficherNPI(out <<"Affichage NPI division"<< endl);

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else
        {
           cout << "N/A" << endl;
        }
    }
}

void FenPrincipale::affichageVal()
{

    bool ok;
    int i(0);
    vector<Constante> tab(2, 0);

    QString op, test;
    ostringstream out;

    QFile fichier(*fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    while(! flux.atEnd())
    {
        flux >> mot;

        float flo = mot.toFloat(&ok);
        if(ok)
        {
            tab[i] = flo;
            i++;
        }
        else
        {
            if (mot == "+" || mot == "-" || mot == "*" || mot == "/")
            op = mot;
        }

        if (op == '+' && i > 1)
        {
            //Création d'une addition
            Addition add1(&tab[0], &tab[1]);

            float resultat = add1.calculer();

            out << resultat << endl;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '-' && i > 1)
        {
            //Création d'une soustraction
            Soustraction sous1(&tab[0], &tab[1]);

            float resultat = sous1.calculer();

            out << resultat << endl;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '*' && i > 1)
        {
            //Création d'une multiplication
            Multiplication mux1(&tab[0], &tab[1]);

            float resultat = mux1.calculer();

            out << resultat << endl;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else if (op == '/' && i > 1)
        {
            //Création d'une division
            Division div1(&tab[0], &tab[1]);

            float resultat = div1.calculer();

            out << resultat << endl;

            test = QString::fromStdString(out.str());
            textEdit->setPlainText(test);
            i=0;
        }
        else
        {
           cout << "N/A" << endl;
        }
    }
}

void FenPrincipale::affichageGraph()
{
/*
    QString op, test;
    ostringstream out;

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    out << "Design pattern - singleton non disponible" << endl;

    test = QString::fromStdString(out.str());
    textEdit->setPlainText(test);    */


    saisieGraphe = new SaisieGraphe();
    saisieGraphe->show();


#ifdef DEBUG

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

#endif

}

void FenPrincipale::affichageSimplification()
{

    QString op, test;
    ostringstream out;

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    out << "Design pattern - singleton non disponible" << endl;

    test = QString::fromStdString(out.str());
    textEdit->setPlainText(test);


#ifdef DEBUG

    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

#endif

}
