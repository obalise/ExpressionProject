#include "fenetresimplification.h"
#include "ui_fenetresimplification.h"
#include <string>

FenetreSimplification::FenetreSimplification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreSimplification)
{
    ui->setupUi(this);
//    ui->AffichageAvantSimplificationNC->setText("Rien du tout!");

 /* std::stringstream chaine;
    chaine << *_monExpression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    ui->AffichageAvantSimplificationNC->setText(qstr);*/
}

FenetreSimplification::~FenetreSimplification()
{
    delete ui;
}

void FenetreSimplification::remplissageAffichages()
{
    std::stringstream chaine;
    chaine << *_monExpression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    ui->AffichageAvantSimplificationNC->setText(qstr);

    Expression* expressionSimplifiee = _monExpression->simplifier();
    std::stringstream chaine2;
    chaine2 << *expressionSimplifiee;
    std::string s2 = chaine2.str();
    QString qstr2 = QString::fromStdString(s2);
    ui->AffichageSimplifieNC->setText(qstr2);

}
