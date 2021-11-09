#include "SaisieGraphe.h"
#include "ui_SaisieGraphe.h"

NewMainWindow *newWin = 0; //utilisé pour créé une nouvelle fenêtre

Saisie::Saisie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("Ici s'affichera l'expression en NPI");
    ui->lineEdit_2->setText("Ici s'affichera l'expression en NC");
}

Saisie::~Saisie()
{
    delete ui;
}


void Saisie::on_pushButton_clicked()   //Constante
{
    Expression* pConstante = new Constante(_nombreConstanteSaisie);
    pileExpression.push(pConstante);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = QString::number(_nombreConstanteSaisie);

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);


}


void Saisie::on_pushButton_6_clicked() //Variable
{
    Expression *pVariable = new Variable('y');
    pileExpression.push(pVariable);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = "y";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_pushButton_2_clicked() //Addition
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pAddition = new Addition(pOperande1, pOperande2);

    pileExpression.push(pAddition);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = "+";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_pushButton_4_clicked() //Soustraction
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pSoustraction = new Soustraction(pOperande1, pOperande2);

    pileExpression.push(pSoustraction);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = "-";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);
}


void Saisie::on_pushButton_3_clicked() //Multiplication
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pMultiplication = new Multiplication(pOperande1, pOperande2);

    pileExpression.push(pMultiplication);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = "*";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_pushButton_5_clicked() //Division
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pDivision = new Division(pOperande1, pOperande2);

    pileExpression.push(pDivision);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = "/";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }


    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}



void Saisie::on_pushButton_7_clicked() //Tracer le graphe
{
    Expression* expression = pileExpression.top();

    //Gestion du titre du graphe => une chaine de caractere de l'expression
    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

    Graphe graphe(_nombrePlageBasseSaisie , _nombrePlageHauteSaisie, _nombrePasSaisie);

    QChartView* florent = graphe.calculerTracerGraphe(expression, qstr);

    newWin = new NewMainWindow();
    newWin->setCentralWidget(florent);
    newWin->resize(400, 300);
    newWin->show();

}



void Saisie::on_doubleSpinBox_valueChanged(double arg1) //Pas
{
    _nombrePasSaisie = arg1;
}


void Saisie::on_doubleSpinBox_2_valueChanged(double arg1) //Minimum
{
    _nombrePlageBasseSaisie = arg1;
}


void Saisie::on_doubleSpinBox_3_valueChanged(double arg1) //Maximum
{
    _nombrePlageHauteSaisie = arg1;
}


void Saisie::on_doubleSpinBox_4_valueChanged(double arg1) //Constante
{
    _nombreConstanteSaisie = arg1;
}

