#pragma once

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

#include "fenetregraphe.h"

namespace Ui {
class SaisieExpressionGraphe;
}

class SaisieExpressionGraphe : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaisieExpressionGraphe(QWidget *parent = nullptr);
    ~SaisieExpressionGraphe();

private slots:
    void on_Bouton_Constante_clicked();

    void on_Bouton_Variable_clicked();


    void on_Bouton_Addition_clicked();

    void on_Bouton_Multiplication_clicked();

    void on_Bouton_Puissance_clicked();

    void on_Bouton_Soustraction_clicked();

    void on_Bouton_Inverse_clicked();

    void on_Bouton_Division_clicked();

    void on_Bouton_ValAbs_clicked();

    void on_Bouton_Simplifier_clicked();

    void on_Bouton_Carre_clicked();

    void on_SpinBox_Constante_valueChanged(double arg1);

private:
    Ui::SaisieExpressionGraphe *ui;
    std::stack<Expression*> pileExpression;
    double _nombreConstanteSaisie;

};
