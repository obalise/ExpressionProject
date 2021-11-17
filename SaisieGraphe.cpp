#include "SaisieGraphe.h"
#include "ui_SaisieGraphe.h"

//NewMainWindow *newWin = 0; //utilisé pour créé une nouvelle fenêtre

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

    //Gestion du titre du graphe => une chaine de caractere de l'expression
    std::stringstream chaine;
    chaine << *_monExpression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);


    Graphe graphe(_nombrePlageBasseSaisie , _nombrePlageHauteSaisie, _nombrePasSaisie);

    QChartView* florent = graphe.calculerTracerGraphe(_monExpression, qstr);

    NewMainWindow *newWin = 0;
    newWin = new NewMainWindow();
    newWin->setCentralWidget(florent);
    newWin->resize(400, 300);
    newWin->show();

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


