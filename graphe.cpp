#include "graphe.h"
#include "Variable.h"

Graphe::Graphe()
{
    //Constructor
}

Graphe::Graphe(float plageBasseX, float plageHauteX, float pas)
{
    //Constructor
    _plageBasseX = plageBasseX;
    _plageHauteX = plageHauteX;
    _pas = pas;
}

Graphe::~Graphe()
{
   //Destructor
}

void Graphe::calculerPointsGrapheDUR()
{

    float i = _plageBasseX;
    while (i <= _plageHauteX)
    {
      float y = 3 * i * i + 5;       //Là ou on devra exploiter la fonction du groupe  -> ITERATION1
     //spéciale à faire
      _series->append(i, y);
      i += _pas;
    }
}


void Graphe::calculerPointsGraphe(Expression* arnaud)
{

    //Je chope mon expression passé en paramètre
    //Il faut que j'identifie ma variable dedans

    variableglobaldemoncul = _plageBasseX;
    while (variableglobaldemoncul <= _plageHauteX)
    {
        float y = arnaud->calculer();

        _series->append(variableglobaldemoncul, y);
        variableglobaldemoncul += _pas;

    }
}

int Graphe::tracerGraphe(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(_series);
    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");
//![3]

//![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();

    return a.exec();
}
