#include "saisieexpressionIHM.h"
#include "ui_saisieexpressionIHM.h"


SaisieExpressionIHM::SaisieExpressionIHM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaisieExpressionGraphe)
{
    ui->setupUi(this);
    ui->AffichageNPI->setText("Ici s'affichera l'expression en NPI");
    ui->AffichageNC->setText("Ici s'affichera l'expression en NC");
}

SaisieExpressionIHM::~SaisieExpressionIHM()
{
    delete ui;
}

void SaisieExpressionIHM::setExpressionSaisie(Expression* expressionsaisie)
{

    _monExpression = expressionsaisie;
}

Expression* SaisieExpressionIHM::retourExpression()
{
    return _monExpression;
}


void SaisieExpressionIHM::on_Bouton_Constante_clicked()
{
    Expression* pConstante = new Constante(_nombreConstanteSaisie);
    pileExpression.push(pConstante);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = QString::number(_nombreConstanteSaisie);

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_Variable_clicked()
{
    Expression *pVariable = new Variable('y');
    pileExpression.push(pVariable);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "y";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}




void SaisieExpressionIHM::on_Bouton_Addition_clicked()
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pAddition = new Addition(pOperande1, pOperande2);

    pileExpression.push(pAddition);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "+";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_Multiplication_clicked()
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pMultiplication = new Multiplication(pOperande1, pOperande2);

    pileExpression.push(pMultiplication);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "*";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_Puissance_clicked()
{

}


void SaisieExpressionIHM::on_Bouton_Soustraction_clicked()
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pSoustraction = new Soustraction(pOperande1, pOperande2);

    pileExpression.push(pSoustraction);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "-";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}



void SaisieExpressionIHM::on_Bouton_Inverse_clicked()
{

}


void SaisieExpressionIHM::on_Bouton_Division_clicked()
{
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pDivision = new Division(pOperande1, pOperande2);

    pileExpression.push(pDivision);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "/";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + " " + valeurAjout);
    }


    Expression* expression = pileExpression.top();
    //setExpressionSaisie(expression);

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_ValAbs_clicked()
{

}


void SaisieExpressionIHM::on_Bouton_Simplifier_clicked()
{

}


void SaisieExpressionIHM::on_Bouton_Carre_clicked()
{

}


void SaisieExpressionIHM::on_SpinBox_Constante_valueChanged(double arg1)
{
    _nombreConstanteSaisie = arg1;
}


void SaisieExpressionIHM::on_Bouton_Memoriser_clicked()
{

    Expression* expression = pileExpression.top();
    _monExpression = expression;
}

void SaisieExpressionIHM::closeEvent(QCloseEvent *bar)
{
/* Quand la fenêtre SaisieExpressionIHM est fermé
 *
 */
    emit closed();
    bar->accept();
}
