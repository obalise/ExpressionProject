#include "SaisieGraphe.h"
#include "ui_SaisieGraphe.h"


SaisieGraphe::SaisieGraphe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

SaisieGraphe::~SaisieGraphe()
{
    delete ui;
}



void SaisieGraphe::on_pushButton_7_clicked() //Tracer le graphe
{


    /*/Gestion du titre du graphe => une chaine de caractere de l'expression/*/
    //Faire une fonction à part ?
    std::stringstream chaine;
    chaine << *_monExpression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);


    Graphe graphe(_nombrePlageBasseSaisie , _nombrePlageHauteSaisie, _nombrePasSaisie);

    QChartView* chartViewGraphe = graphe.calculerTracerGraphe(_monExpression, qstr);

    NewMainWindow *nouvelleFenetre = 0;
    nouvelleFenetre = new NewMainWindow();
    nouvelleFenetre->setCentralWidget(chartViewGraphe);
    nouvelleFenetre->resize(400, 300);
    nouvelleFenetre->show();

}


void SaisieGraphe::on_doubleSpinBox_valueChanged(double arg1) //Pas
{
    _nombrePasSaisie = arg1;
}


void SaisieGraphe::on_doubleSpinBox_2_valueChanged(double arg1) //Minimum
{
    _nombrePlageBasseSaisie = arg1;
}


void SaisieGraphe::on_doubleSpinBox_3_valueChanged(double arg1) //Maximum
{
    _nombrePlageHauteSaisie = arg1;
}


