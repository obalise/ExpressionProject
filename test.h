#ifndef TEST_H
#define TEST_H

#include <QMainWindow>

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

#include "Graphe.h"
#include "Expression.h"
#include "Constante.h"
#include "Multiplication.h"
#include "Addition.h"
#include "Soustraction.h"
#include "Division.h"
#include "Constante.h"
#include "Variable.h"

#include "affichage_graphe.h"


namespace Ui {
class TEST;
}

class TEST : public QMainWindow
{
    Q_OBJECT

public:
    explicit TEST(QWidget *parent = nullptr, Expression* expression = nullptr);
    explicit TEST(QWidget *parent = nullptr);
    ~TEST();

private:
    Ui::TEST *ui;
};

#endif // TEST_H
