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


public:
    Graphe();
    Graphe(float, float, float);
    ~Graphe();

    void set_pas(float);
    void set_plageBasseX(float);
    void set_plageHauteX(float);


    void calculerPointsGrapheDUR();
    void calculerPointsGraphe(Expression* expression);
    int tracerGraphe(QString qstr, int argc, char *argv[]);

    QChartView* calculerTracerGraphe(Expression* expression, QString qstr);


};

#endif // GRAPHE_H
