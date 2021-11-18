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
    /*/Paramètres pour notre graphe, le pas et "l'étendu abscisse" sur lequel sera tracé le graphe/*/
    float _pas;
    float _plageBasseX;
    float _plageHauteX;

    /*/Contient la série de point calculée/*/
    QLineSeries *_series = new QLineSeries();

public:
    /*/Constructeurs et Destructeurs/*/
    Graphe();
    Graphe(float, float, float);
    ~Graphe();

    /*/Uniquement des setters, pas de getters nécéssaires/*/
    void set_pas(float);
    void set_plageBasseX(float);
    void set_plageHauteX(float);

    /*/Prend une expression et la trace selon les paramètres en private/*/
    QChartView* calculerTracerGraphe(Expression* expression, QString qstr); //qstr contient le titre du graphe


};

#endif // GRAPHE_H
