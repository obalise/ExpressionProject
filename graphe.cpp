#include <iostream>
#include <sstream>
#include <string>

#include "graphe.h"
#include "Variable.h"


Graphe::Graphe()
{
    //Constructor
}

Graphe::Graphe(float plageBasseX, float plageHauteX, float pas)
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

void Graphe::calculerPointsGrapheDUR()
{

    float i = _plageBasseX;
    while (i <= _plageHauteX)
    {
      float y = 3 * i * i + 5;       //Là ou on devra exploiter la fonction du groupe  -> ITERATION1
     //spéciale à faire
      _series->append(i, y);
      i += _pas;
    }
}


void Graphe::calculerPointsGraphe(Expression* expression)
{

    //Je chope mon expression passé en paramètre
    //Il faut que j'identifie ma variable dedans

    vGlobValVar = _plageBasseX;
    while (vGlobValVar <= _plageHauteX)
    {
        float y = expression->calculer();

        _series->append(vGlobValVar, y);
        vGlobValVar += _pas;

    }

}


QChartView* Graphe::calculerPointsGrapheTEST(Expression* expression, QString qstr)
{

    //Je chope mon expression passé en paramètre
    //Il faut que j'identifie ma variable dedans

    vGlobValVar = _plageBasseX;
    while (vGlobValVar <= _plageHauteX)
    {
        float y = expression->calculer();

        _series->append(vGlobValVar, y);
        vGlobValVar += _pas;

    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(_series);
    chart->createDefaultAxes();

    chart->setTitle(qstr);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;

}

int Graphe::tracerGraphe(QString qstr, int argc, char *argv[])
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
