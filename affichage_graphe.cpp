#include "affichage_graphe.h"
#include "ui_affichage_graphe.h"

Affichage_graphe::Affichage_graphe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affichage_graphe)
{
    ui->setupUi(this);
}

Affichage_graphe::~Affichage_graphe()
{
    delete ui;
}
