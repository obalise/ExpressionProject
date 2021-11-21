#include <vector>
#include <sstream>
#include <string>
#include <iostream>

#include <QEventLoop>

#include "SaisieGraphe.h"
#include "saisieexpressionIHM.h"
#include "fenetresimplification.h"


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

    QPixmap bkgnd(":/Images/HEYHEYHEYHEYHYE.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // Création menu pour la fenêtre principale
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    //menuFichier->setIcon(this->style()->standardIcon(QStyle::SP_DialogOpenButton));
    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    //menuEdition->setIcon(this->style()->standardIcon(QStyle::SP_TitleBarMenuButton));
    QMenu *menuOutils = menuBar()->addMenu("&Outils");
    //menuOutils->setIcon(this->style()->standardIcon(QStyle::SP_ToolBarHorizontalExtensionButton));

    //Création d'actions pour les menus
    QAction *actionSauvegarderFichier = new QAction("&Sauvegarder fichier", this);
    QAction *actionCharger = new QAction("&Charger Fichier", this);
    actionSauvegarderFichier->setIcon(this->style()->standardIcon(QStyle::SP_DialogSaveButton));
    actionCharger->setIcon(this->style()->standardIcon(QStyle::SP_DialogOpenButton));
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setIcon(this->style()->standardIcon(QStyle::SP_TitleBarCloseButton));



    QAction *actionSaisie = new QAction("&Saisie de l'expression", this);
    QAction *actionSauvegarderExpression = new QAction("&Sauvegarder expression", this);
    actionSaisie->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));
    QAction *actionAffichageNC = new QAction("&Affichage de l'expression en NC", this);
    actionAffichageNC->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));
    QAction *actionAffichageNPI = new QAction("&Affichage de l'expression en NPI", this);
    actionAffichageNPI->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));
    QAction *actionAffichageVal = new QAction("&Affichage de la valeur de l'expression", this);
    actionAffichageVal->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));
    QAction *actionAffichageGraph = new QAction("&Affichage graphique en 2D ", this);
    actionAffichageGraph->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));

    QAction *actionSimplification = new QAction("&Simplification de l'expression", this);
    actionSimplification->setIcon(this->style()->standardIcon(QStyle::SP_ArrowRight));

    menuFichier->addAction(actionSauvegarderFichier);
    menuFichier->addAction(actionCharger);
    menuFichier->addAction(actionQuitter);

    menuEdition->addAction(actionSaisie);
    menuEdition->addAction(actionSauvegarderExpression);
    menuEdition->addAction(actionAffichageNC);
    menuEdition->addAction(actionAffichageNPI);
    menuEdition->addAction(actionAffichageVal);
    menuEdition->addAction(actionAffichageGraph);

    menuOutils->addAction(actionSimplification);

    //Connection avec les slots
    connect(actionSauvegarderFichier, SIGNAL(triggered()), this, SLOT(sauvegarderFichier()));
    connect(actionCharger, SIGNAL(triggered()), this, SLOT(charger()));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(actionSaisie, SIGNAL(triggered()), this, SLOT(saisie()));
    connect(actionSauvegarderExpression, SIGNAL(triggered()), this, SLOT(sauvegarderExpression()));
    connect(actionAffichageNC, SIGNAL(triggered()), this, SLOT(affichageNC()));
    connect(actionAffichageNPI, SIGNAL(triggered()), this, SLOT(affichageNPI()));
    connect(actionAffichageVal, SIGNAL(triggered()), this, SLOT(affichageVal()));
    connect(actionAffichageGraph, SIGNAL(triggered()), this, SLOT(affichageGraph()));

    connect(actionSimplification, SIGNAL(triggered()), this, SLOT(affichageSimplification()));

}

Expression* FenPrincipale::getExpression()
{
    return _monExpression;
}

void FenPrincipale::setExpression(Expression* expression)
{

    _monExpression = expression;

}

void FenPrincipale::saisie()
{

    //zone centrale : SDI edition texte
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    textEdit->clear();

}

bool FenPrincipale::sauvegarderFichier()
{

    /* Sauvegarde fichier edition courante */
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

    /* Chargement d'un fichier texte par navigation */
    //zone centrale : SDI
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textEdit);
    zoneCentrale->setLayout(layout);

    textEdit->clear();

    *fileName = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Fichier textes (*.txt)");


    QFile file(*fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Projet6"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(*fileName), file.errorString()));
        return;
    }

    /* On affiche le contenu du fichier dans le layout */
    QTextStream in(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    textEdit->setPlainText(in.readAll());
    QGuiApplication::restoreOverrideCursor();

}

bool FenPrincipale::sauvegarderExpression()
{

    /* Sauvegarde de l'expression utilisation du flux texte avec post traitement */
    bool ok;
    int i(0), j(0);
    vector<Constante> tab(10,0);

    float resultat;

    QString op, test;
    ostringstream out, out1, out2, out3, out4, out5, out6, out7, out8, out9;

    texte = textEdit->toPlainText();

    if (texte.isEmpty())
    {
        out << "Vous n'avez pas entré d'expression." << endl;
        test = QString::fromStdString(out.str());
        textEdit->setPlainText(test);
        return false;
    }

    QTextStream flux(&texte);

    while(! flux.atEnd())
    {
        flux >> mot;

        float flo = mot.toFloat(&ok);

        if(ok)
        {
            tab[i] = flo;
            i++;
        }
        else if (mot == "+" || mot == "-" || mot == "*" || mot == "/")
        {
            op = mot;
            j++;
        }

        if (j == 1)
        {
            if (op == '+' && i == 2 && mot != "(" && mot != ")")
            {
                //Création d'une addition
                add1 =  new Addition(&tab[0], &tab[1]);

                add1->afficher(out1 <<"Affichage NC addition"<< endl);

                add1->afficherNPI(out2 <<"Affichage NPI addition"<< endl);

                resultat = add1->calculer();
                out3 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(add1);

            }
            else if (op == '-' && i == 2 && mot != "(" && mot != ")")
            {
                //Création d'une soustraction
                sous1 = new Soustraction(&tab[0], &tab[1]);

                sous1->afficher(out1 << "Affichage NC soustraction" << endl);

                sous1->afficherNPI(out2 <<"Affichage NPI soustraction"<< endl);

                resultat = sous1->calculer();
                out3 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(sous1);

            }
            else if (op == '*' && i == 2 && mot != "(" && mot != ")")
            {
                //Création d'une multiplication
                mux1 = new Multiplication(&tab[0], &tab[1]);

                mux1->afficher(out1 << "Affichage NC multiplication" << endl);

                mux1->afficherNPI(out2 <<"Affichage NPI multiplication"<< endl);

                resultat = mux1->calculer();
                out3 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(mux1);

            }
            else if (op == '/' && i == 2 && mot != "(" && mot != ")")
            {
                //Création d'une division
                div1 = new Division(&tab[0], &tab[1]);

                div1->afficher(out1 << "Affichage NC division" << endl);

                div1->afficherNPI(out2 <<"Affichage NPI division"<< endl);

                resultat = div1->calculer();
                out3 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(div1);

            }
        }else if (j == 2 && i == 3 && mot != "(" && mot != ")"){

            if (op == '+')
            {

                //Création d'une addition

                add2 = new Addition(this->getExpression(), &tab[2]);

                add2->afficher(out4 << "Affichage NC addition" << endl);

                add2->afficherNPI(out5 <<"Affichage NPI addition"<< endl);

                resultat = add2->calculer();
                out6 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(add2);

            }
            else if (op == '-')
            {
                //Création d'une soustraction
                sous2 = new Soustraction(this->getExpression(), &tab[2]);

                sous2->afficher(out4 << "Affichage NC soustraction" << endl);

                sous2->afficherNPI(out5 <<"Affichage NPI soustraction"<< endl);

                resultat = sous2->calculer();
                out6 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(sous2);

            }
            else if (op == '*')
            {
                //Création d'une multiplication
                mux2 = new Multiplication(this->getExpression(), &tab[2]);

                mux2->afficher(out4 << "Affichage NC multiplication" << endl);

                mux2->afficherNPI(out5 <<"Affichage NPI multiplication"<< endl);

                resultat = mux2->calculer();
                out6 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(mux2);

            }
            else
            {
                //Création d'une division
                div2 = new Division(this->getExpression(), &tab[2]);

                div2->afficher(out4 << "Affichage NC division" << endl);

                div2->afficherNPI(out5 <<"Affichage NPI division"<< endl);

                resultat = div2->calculer();
                out6 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(div2);

            }

        }else if (j == 3 && i == 4 && mot != "(" && mot != ")"){

            if (op == '+')
            {

                //Création d'une addition

                add3 = new Addition(this->getExpression(), &tab[3]);

                add3->afficher(out7 << "Affichage NC addition" << endl);

                add3->afficherNPI(out8 <<"Affichage NPI addition"<< endl);

                resultat = add3->calculer();
                out9 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(add3);

            }
            else if (op == '-')
            {
                //Création d'une soustraction
                sous2 = new Soustraction(this->getExpression(), &tab[3]);

                sous2->afficher(out7 << "Affichage NC soustraction" << endl);

                sous2->afficherNPI(out8 <<"Affichage NPI soustraction"<< endl);

                resultat = sous2->calculer();
                out9 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(sous2);

            }
            else if (op == '*')
            {
                //Création d'une multiplication
                mux2 = new Multiplication(this->getExpression(), &tab[3]);

                mux2->afficher(out7 << "Affichage NC multiplication" << endl);

                mux2->afficherNPI(out8 <<"Affichage NPI multiplication"<< endl);

                resultat = mux2->calculer();
                out9 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(mux2);

            }
            else
            {
                //Création d'une division
                div2 = new Division(this->getExpression(), &tab[3]);

                div2->afficher(out7 << "Affichage NC division" << endl);

                div2->afficherNPI(out8 <<"Affichage NPI division"<< endl);

                resultat = div2->calculer();
                out9 << "Affichage du résultat =" << resultat << endl;

                this->setExpression(div2);

            }

        }
    }
    if (j ==1)
    {
        _affichageNC = QString::fromStdString(out1.str());

        _affichageNPI = QString::fromStdString(out2.str());

        _affichageCalcul = QString::fromStdString(out3.str());

    }else if(j == 2)
    {
        _affichageNC = QString::fromStdString(out4.str());

        _affichageNPI = QString::fromStdString(out5.str());

        _affichageCalcul = QString::fromStdString(out6.str());

    }else if(j == 3)
    {
        _affichageNC = QString::fromStdString(out7.str());

        _affichageNPI = QString::fromStdString(out8.str());

        _affichageCalcul = QString::fromStdString(out9.str());
    }

    return true;
}

void FenPrincipale::affichageNC()
{

    /* Affichage en normal condition utilisation du flux texte avec post traitement */

    QString test;
    ostringstream out;

    if (texte.isEmpty()){
        out << "Vous n'avez pas sauvegardé l'expression." << endl;

        test = QString::fromStdString(out.str());
        textEdit->setPlainText(test);
    }

    textEdit->setPlainText(_affichageNC);

}

void FenPrincipale::affichageNPI()
{

    /* Affichage en polonaise inversée utilisation du flux texte avec post traitement */

    QString test;
    ostringstream out;

    if (texte.isEmpty()){
        out << "Vous n'avez pas sauvegardé l'expression." << endl;

        test = QString::fromStdString(out.str());
        textEdit->setPlainText(test);
    }

    textEdit->setPlainText(_affichageNPI);

}

void FenPrincipale::affichageVal()
{

    /* Calcule et affichage de l'expression, utilisation du flux texte avec post traitement*/

    QString test;
    ostringstream out;

    if (texte.isEmpty()){
        out << "Vous n'avez pas sauvegardé l'expression." << endl;

        test = QString::fromStdString(out.str());
        textEdit->setPlainText(test);
    }

    textEdit->setPlainText(_affichageCalcul);
}

void FenPrincipale::affichageGraph()
{

    std::cout << "\nAffichage graphe" << _monExpression;
    std::cout << "\nAffichage graphe" << *_monExpression;

    FenetreSimplification *fenSimplification = 0;
    fenSimplification = new FenetreSimplification();
    fenSimplification->_monExpression = this->getExpression();
    fenSimplification->remplissageAffichages();
    fenSimplification->show();

 }

#ifdef DEBUG

void FenPrincipale::affichageSimplification()
{


}
