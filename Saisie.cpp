#include "Saisie.h"
#include "ui_Saisie.h"

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
   // QMessageBox::information(this, "Constante", "Vous avez cliqué sur constante");
    Expression* pConstante = new Constante(_nombreConstanteSaisie);
    pileExpression.push(pConstante);

    QString valeurEcran = ui->lineEdit->text();
    QString valeurAjout = QString::number(_nombreConstanteSaisie);

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->lineEdit->setText(valeurAjout);
    } else{
       ui->lineEdit->setText(valeurEcran + " " + valeurAjout);
    }

    //cout << *pConstante << "  " << endl;
    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);


}


void Saisie::on_pushButton_6_clicked() //Variable
{
    //QMessageBox::information(this, "Variable", "Vous avez cliqué sur variable");

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

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_pushButton_2_clicked() //Addition
{
   // QMessageBox::information(this, "Addition", "Vous avez cliqué sur addition");

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

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_pushButton_4_clicked() //Soustraction
{
    //QMessageBox::information(this, "Soustraction", "Vous avez cliqué sur soustraction");

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

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);
}


void Saisie::on_pushButton_3_clicked() //Multiplication
{
    //QMessageBox::information(this, "Multiplication", "Vous avez cliqué sur multiplication");

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

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

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

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

}


void Saisie::on_spinBox_valueChanged(int arg1) //Changement de valeur pour la constante
{
    _nombreConstanteSaisie = arg1;
}


void Saisie::on_pushButton_7_clicked() //Tracer le graphe
{
    //QMessageBox::information(this, "Tracer graphe", "Vous avez cliqué sur tracer le graphe");


    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurEcran2 = ui->lineEdit_2->text();
    QString valeurAjout2 = qstr;

    ui->lineEdit_2->setText(valeurAjout2);

    Graphe graphe(0, 45, 0.5);

    QChartView* florent = graphe.calculerPointsGrapheTEST(expression, qstr);

    newWin = new NewMainWindow();
    newWin->setCentralWidget(florent);
    newWin->resize(400, 300);
    newWin->show();


}


void Saisie::on_pushButton_8_clicked() //Afficher l'expression saisie
{
    QMessageBox::information(this, "Afficher expression saisie", "Vous avez cliqué sur afficher exp saisie");

    Expression* yolesang = pileExpression.top();

    //float y = yolesang->calculer();

    cout << "Expression: " << *yolesang <<endl;

    //affichage de la pile et vidage de la pile
/*    while(!pileExpression.empty()) {
        cout << "Hello les amis ! " << *pileExpression.top() << endl;
        pileExpression.pop();
    } */

}

