#include "fenetregraphe.h"
#include "ui_FenetreGraphe.h"

FenetreGraphe::FenetreGraphe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewMainWindow)
{
    ui->setupUi(this);
}

FenetreGraphe::~FenetreGraphe()
{
    delete ui;
}


//Permet d'avoir la nouvelle fenêtre pour afficher notre courbe
