#include "fenetresimplification.h"
#include "ui_fenetresimplification.h"

FenetreSimplification::FenetreSimplification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenetreSimplification)
{
    ui->setupUi(this);
}

FenetreSimplification::~FenetreSimplification()
{
    delete ui;
}
