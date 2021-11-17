#ifndef SAISIEGRAPHE_H
#define SAISIEGRAPHE_H

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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class SaisieGraphe : public QMainWindow
{
    Q_OBJECT

public:
    SaisieGraphe(QWidget *parent = nullptr);
    ~SaisieGraphe();
    Expression* _monExpression;

private:
    Ui::MainWindow *ui;
    std::stack<Expression*> pileExpression;
    double _nombrePasSaisie;
    double _nombrePlageBasseSaisie;
    double _nombrePlageHauteSaisie;

private slots:
    void on_pushButton_7_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);
    void on_doubleSpinBox_2_valueChanged(double arg1);
    void on_doubleSpinBox_3_valueChanged(double arg1);
};
#endif // SAISIEGRAPHE_H
