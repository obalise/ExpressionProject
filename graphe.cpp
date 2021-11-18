#include <iostream>
#include <sstream>
#include <string>

#include "graphe.h"
#include "Variable.h"


Graphe::Graphe()
{
    //Constructeur du Graphe par défaut
}

Graphe::Graphe(float plageBasseX, float plageHauteX, float pas)
{
    //Constructeur du Graphe permettant de prendre les différents paramètres
    _plageBasseX = plageBasseX;
    _plageHauteX = plageHauteX;
    _pas = pas;
}

Graphe::~Graphe()
{
   //Destructeur du Graphe par défaut, pas d'allocation de mémoire donc pas de delete
}


/*/Setters des paramètres pour tracer le graphe/*/
void Graphe::set_pas(float pas){
    _pas = pas;
}
void Graphe::set_plageBasseX(float plageBasseX){
    _plageBasseX = plageBasseX;
}
void Graphe::set_plageHauteX(float plageHauteX){
    _plageHauteX = plageHauteX;
}



QChartView* Graphe::calculerTracerGraphe(Expression* expression, QString qstr)
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

