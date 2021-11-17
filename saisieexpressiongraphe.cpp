#include "saisieexpressiongraphe.h"
#include "ui_saisieexpressiongraphe.h"

SaisieExpressionGraphe::SaisieExpressionGraphe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaisieExpressionGraphe)
{
    ui->setupUi(this);
}

SaisieExpressionGraphe::~SaisieExpressionGraphe()
{
    delete ui;
}
