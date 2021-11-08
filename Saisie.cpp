#include "Saisie.h"
#include "ui_Saisie.h"

NewMainWindow *newWin = 0;

Saisie::Saisie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Saisie::~Saisie()
{
    delete ui;
}


void Saisie::on_pushButton_clicked()   //Constante
{
    QMessageBox::information(this, "Constante", "Vous avez cliqué sur constante");
    //Ici qu'on va mettre qui traite les constante

    Expression* pConstante = new Constante(_nombreConstante);

    //shared_ptr<Expression> pConstante(constante);

    pileExpression.push(pConstante);

    //vecExpression.push_back(pConstante);

    cout << *pConstante << "  " << endl;

}


void Saisie::on_pushButton_6_clicked() //Variable
{
    QMessageBox::information(this, "Variable", "Vous avez cliqué sur variable");

    Expression *pVariable = new Variable('y');

    pileExpression.push(pVariable);


}


void Saisie::on_pushButton_2_clicked() //Addition
{
    QMessageBox::information(this, "Addition", "Vous avez cliqué sur addition");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pAddition = new Addition(pOperande1, pOperande2);

    pileExpression.push(pAddition);

}


void Saisie::on_pushButton_4_clicked() //Soustraction
{
    QMessageBox::information(this, "Soustraction", "Vous avez cliqué sur soustraction");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pSoustraction = new Soustraction(pOperande1, pOperande2);

    pileExpression.push(pSoustraction);
}


void Saisie::on_pushButton_3_clicked() //Multiplication
{
    QMessageBox::information(this, "Multiplication", "Vous avez cliqué sur multiplication");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pMultiplication = new Multiplication(pOperande1, pOperande2);

    pileExpression.push(pMultiplication);
}


void Saisie::on_pushButton_5_clicked() //Division
{
    QMessageBox::information(this, "Division", "Vous avez cliqué sur division");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pDivision = new Division(pOperande1, pOperande2);

    pileExpression.push(pDivision);
}


void Saisie::on_spinBox_valueChanged(int arg1) //Changement de valeur pour la constante
{
    _nombreConstante = arg1;
}


void Saisie::on_pushButton_7_clicked() //Tracer le graphe
{
    QMessageBox::information(this, "Tracer graphe", "Vous avez cliqué sur tracer le graphe");

  /*  Dialog fenetre;
    fenetre.setModal(true);
    fenetre.exec();

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


    newWin = new NewMainWindow();
    newWin->setCentralWidget(chartView);
    newWin->resize(400, 300);
    newWin->show(); */


    Expression* expression = pileExpression.top();


    std::stringstream chaine;
    chaine << expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    Graphe arnaud(0, 45, 0.5);



    QChartView* florent = arnaud.calculerPointsGrapheTEST(expression);


    newWin = new NewMainWindow();
    newWin->setCentralWidget(florent);
    newWin->resize(400, 300);
    newWin->show();


}


void Saisie::on_pushButton_8_clicked() //Afficher l'expression saisie
{
    QMessageBox::information(this, "Afficher expression saisie", "Vous avez cliqué sur afficher exp saisie");

    Expression* yolesang = pileExpression.top();

    float y = yolesang->calculer();

    cout << "Arnaud le pédé : " << y << endl;


    //affichage de la pile et vidage de la pile
    while(!pileExpression.empty()) {
        cout << "Hello les amis ! " << *pileExpression.top() << endl;
        pileExpression.pop();
    }

}

