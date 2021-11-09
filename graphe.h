#ifndef GRAPHE_H
#define GRAPHE_H
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "Expression.h"

QT_CHARTS_USE_NAMESPACE

class Graphe
{
private:

    float _pas;
    float _plageBasseX;
    float _plageHauteX;

    QLineSeries *_series = new QLineSeries();

    //Expression _fonction1Variable;

    //Comment on fait rentrer l'expression dans ce bordel de merde.



public:
    Graphe();
    Graphe(float, float, float);
    ~Graphe();

    void calculerPointsGrapheDUR();
    void calculerPointsGraphe(Expression* expression);
    QChartView* calculerPointsGrapheTEST(Expression* expression, QString qstr);

    int tracerGraphe(QString qstr, int argc, char *argv[]); //voir si on a pas de problÃƒÂ¨me quand on intÃƒÂ©grera au main


};

#endif // GRAPHE_H
