#include "test.h"
#include "ui_test.h"

TEST::TEST(QWidget *parent, Expression* expression) :
    QMainWindow(parent),
    ui(new Ui::TEST)
{
    //ui->setupUi(this);

//    std::stringstream chaine;
//    chaine << expression;
//    std::string s = chaine.str();
//    QString qstr = QString::fromStdString(s);

//    Graphe arnaud(0, 45, 0.5);
//    QChartView *chartView;

//    chartView = arnaud.calculerPointsGrapheTEST(expression);

//    setCentralWidget(chartView);
//    resize(400, 300);
//    show();



//![1]
    QLineSeries *series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}

TEST::TEST(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TEST)
{

}

TEST::~TEST()
{
    delete ui;
}
