#include "FenetreGraphe.h"
//#include "ui_newmainwindow.h"
#include "ui_FenetreGraphe.h"

NewMainWindow::NewMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewMainWindow)
{
    ui->setupUi(this);
}

NewMainWindow::~NewMainWindow()
{
    delete ui;
}


//Permet d'avoir la nouvelle fenêtre pour afficher notre courbe