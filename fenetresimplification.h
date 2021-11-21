#ifndef FENETRESIMPLIFICATION_H
#define FENETRESIMPLIFICATION_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

#include "graphe.h"
#include "Expression.h"
#include "Constante.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Constante.h"
#include "Variable.h"

#include "Carre.h"
#include "sinus.h"
#include "cosinus.h"
#include "racinecarree.h"
#include "logneperien.h"

#include "fenetregraphe.h"

namespace Ui {
class FenetreSimplification;
}

class FenetreSimplification : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreSimplification(QWidget *parent = nullptr);
    ~FenetreSimplification();
    void remplissageAffichages();
    Expression* _monExpression;

private:
    Ui::FenetreSimplification *ui;

};

#endif // FENETRESIMPLIFICATION_H
