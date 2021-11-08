#include "fenetregraphe.h"
#include "ui_fenetregraphe.h"

FenetreGraphe::FenetreGraphe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetreGraphe)
{
    ui->setupUi(this);
}

FenetreGraphe::~FenetreGraphe()
{
    delete ui;
}
