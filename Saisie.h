#ifndef SAISIE_H
#define SAISIE_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>


#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Saisie : public QMainWindow
{
    Q_OBJECT

public:
    Saisie(QWidget *parent = nullptr);
    ~Saisie();
    int _nombreConstante;


private:
    Ui::MainWindow *ui;

    //std::vector<Expression*> vecExpression;

    std::stack<Expression*> pileExpression;



private slots:
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
};
#endif // SAISIE_H
