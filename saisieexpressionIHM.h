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
#include "puissance.h"

#include "Carre.h"
#include "sinus.h"
#include "cosinus.h"
#include "tan.h"
#include "racinecarree.h"
#include "logneperien.h"
#include "exponentielle.h"

#include "fenetregraphe.h"

namespace Ui {
class SaisieExpressionGraphe;
}

class SaisieExpressionIHM : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaisieExpressionIHM(QWidget *parent = nullptr);
    ~SaisieExpressionIHM();
    void setExpressionSaisie(Expression*);
    Expression* retourExpression();
    Expression* _monExpression;


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

    void on_Bouton_Carre_clicked();

    void on_SpinBox_Constante_valueChanged(double arg1);

    void on_Bouton_Memoriser_clicked();

    void on_Bouton_Sinus_clicked();

    void on_Bouton_Cosinus_clicked();

    void on_Bouton_RacineCarree_clicked();

    void on_Bouton_Euler_clicked();

    void on_Bouton_LogNeperien_clicked();

    void on_Bouton_Tangente_clicked();

private:
    Ui::SaisieExpressionGraphe *ui;
    std::stack<Expression*> pileExpression;
    double _nombreConstanteSaisie;
    void closeEvent(QCloseEvent *bar);

signals :
    void closed();


};

