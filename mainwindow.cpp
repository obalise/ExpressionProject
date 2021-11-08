#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()   //Constante
{
    QMessageBox::information(this, "Constante", "Vous avez cliqué sur constante");
    //Ici qu'on va mettre qui traite les constante

    Expression* pConstante = new Constante(_nombreConstante);

    //shared_ptr<Expression> pConstante(constante);

    pileExpression.push(pConstante);

    //vecExpression.push_back(pConstante);

    cout << *pConstante << "  " << endl;

}


void MainWindow::on_pushButton_6_clicked() //Variable
{
    QMessageBox::information(this, "Variable", "Vous avez cliqué sur variable");

    Expression *pVariable = new Variable('y');

    pileExpression.push(pVariable);


}


void MainWindow::on_pushButton_2_clicked() //Addition
{
    QMessageBox::information(this, "Addition", "Vous avez cliqué sur addition");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pAddition = new Addition(pOperande1, pOperande2);

    pileExpression.push(pAddition);

}


void MainWindow::on_pushButton_4_clicked() //Soustraction
{
    QMessageBox::information(this, "Soustraction", "Vous avez cliqué sur soustraction");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pSoustraction = new Soustraction(pOperande1, pOperande2);

    pileExpression.push(pSoustraction);
}


void MainWindow::on_pushButton_3_clicked() //Multiplication
{
    QMessageBox::information(this, "Multiplication", "Vous avez cliqué sur multiplication");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pMultiplication = new Multiplication(pOperande1, pOperande2);

    pileExpression.push(pMultiplication);
}


void MainWindow::on_pushButton_5_clicked() //Division
{
    QMessageBox::information(this, "Division", "Vous avez cliqué sur division");

    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pDivision = new Division(pOperande1, pOperande2);

    pileExpression.push(pDivision);
}


void MainWindow::on_spinBox_valueChanged(int arg1) //Changement de valeur pour la constante
{
    _nombreConstante = arg1;
}


void MainWindow::on_pushButton_7_clicked() //Tracer le graphe
{



}


void MainWindow::on_pushButton_8_clicked() //Afficher l'expression saisie
{
    QMessageBox::information(this, "Division", "Vous avez cliqué sur division");

    Expression* yolesang = pileExpression.top();

    float y = yolesang->calculer();

    cout << "Arnaud le pédé : " << y << endl;


    //affichage de la pile et vidage de la pile
    while(!pileExpression.empty()) {
        cout << "Hello les amis ! " << *pileExpression.top() << endl;
        pileExpression.pop();
    }

}

