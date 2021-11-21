#include "saisieexpressionIHM.h"
#include "ui_saisieexpressionIHM.h"

#define PI 3.1415926535

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
    Expression *pOperande2 = pileExpression.top();
    pileExpression.pop();
    Expression *pOperande1 = pileExpression.top();
    pileExpression.pop();
    Expression *pPuissance = new Puissance(pOperande1, pOperande2);

    pileExpression.push(pPuissance);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "^";

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



/*
 *       |          | <- 3
 *
 *       |3         | <- 4
 *
 *       |3 4       | <- +
 *
 *       |          |  <- 3 + 4
 *
 *       |(3+4)     |  <- ²
 *
 *       |          |  <- (3+4)²
 *
 *       |(3+4)²    |  <-
 *
 */


void SaisieExpressionIHM::on_Bouton_Carre_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pCarre = new Carre(pOperande);

    pileExpression.push(pCarre);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "²";

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

void SaisieExpressionIHM::on_Bouton_Sinus_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pSinus = new Sinus(pOperande);

    pileExpression.push(pSinus);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "sin";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_Cosinus_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pCosinus = new Cosinus(pOperande);

    pileExpression.push(pCosinus);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "cos";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_RacineCarree_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pRacineCarree = new RacineCarree(pOperande);

    pileExpression.push(pRacineCarree);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "sqrt";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_Euler_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pExponentielle = new Exponentielle(pOperande);

    pileExpression.push(pExponentielle);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "exp";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}


void SaisieExpressionIHM::on_Bouton_LogNeperien_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pLogNeperien = new LogNeperien(pOperande);

    pileExpression.push(pLogNeperien);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "ln";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}



void SaisieExpressionIHM::on_Bouton_Tangente_clicked()
{
    Expression *pOperande = pileExpression.top();
    pileExpression.pop();
    Expression *pTan = new Tan(pOperande);

    pileExpression.push(pTan);

    QString valeurEcran = ui->AffichageNPI->text();
    QString valeurAjout = "tan";

    if((valeurEcran == "Ici s'affichera l'expression en NPI")){
       ui->AffichageNPI->setText(valeurAjout);
    } else{
       ui->AffichageNPI->setText(valeurEcran + "." + valeurAjout);
    }

    Expression* expression = pileExpression.top();

    std::stringstream chaine;
    chaine << *expression;
    std::string s = chaine.str();
    QString qstr = QString::fromStdString(s);

    QString valeurAjout2 = qstr;

    ui->AffichageNC->setText(valeurAjout2);
}

