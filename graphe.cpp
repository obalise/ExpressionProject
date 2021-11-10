#include <iostream>
#include <sstream>
#include <string>

#include "graphe.h"
#include "Variable.h"


Graphe::Graphe()
{
    //Constructor
}

Graphe::Graphe(float plageBasseX, float plageHauteX, float pas) //Constructeur prenant la plage des abscisses et le pas pour le calcul des points
{
    //Constructor
    _plageBasseX = plageBasseX;
    _plageHauteX = plageHauteX;
    _pas = pas;
}

Graphe::~Graphe()
{
   //Destructor
}

void Graphe::set_pas(float pas){
    _pas = pas;
}
void Graphe::set_plageBasseX(float plageBasseX){
    _plageBasseX = plageBasseX;
}
void Graphe::set_plageHauteX(float plageHauteX){
    _plageHauteX = plageHauteX;
}

void Graphe::calculerPointsGrapheDUR() // [FONCTION ITERATION 1]
{

    float i = _plageBasseX;
    while (i <= _plageHauteX)
    {
      float y = 3 * i * i + 5;
      _series->append(i, y);
      i += _pas;
    }
}


void Graphe::calculerPointsGraphe(Expression* expression) // [FONCTION ITERATION 1]
{
    vGlobValVar = _plageBasseX;
    while (vGlobValVar <= _plageHauteX)
    {
        float y = expression->calculer();

        _series->append(vGlobValVar, y);
        vGlobValVar += _pas;
    }
}


QChartView* Graphe::calculerTracerGraphe(Expression* expression, QString qstr) // [FONCTION ITERATION 2]
/* A partir de notre équation (expression) et du titre du graphe (qstr, ce sera simplement notre équation en chaines de caractères)
 * La fonction retourne un pointeur vers un objet QChartView qui nous permettra par la suite de tracer le graphe
 * Note d'amélioration: il doit être possible de ne pas passer par vGlobValVar !
 */
{
    vGlobValVar = _plageBasseX;
    while (vGlobValVar <= _plageHauteX)
    {
        float y = expression->calculer();

        _series->append(vGlobValVar, y);
        vGlobValVar += _pas;
    }

    //Création de l'objet QChart et de ses différents paramètres
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(_series);
    chart->createDefaultAxes();
    chart->setTitle(qstr);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;

}

int Graphe::tracerGraphe(QString qstr, int argc, char *argv[]) // [FONCTION ITERATION 1] Recréer une QApplication qui doit être unique. A prohiber.
{
    QApplication a(argc, argv);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(_series);
    chart->createDefaultAxes();

    chart->setTitle(qstr);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow windowchart;
    windowchart.setCentralWidget(chartView);
    windowchart.resize(400, 300);
    windowchart.show();

    return a.exec();
}
