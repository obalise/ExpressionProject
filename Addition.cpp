#include <iostream>
#include "Variable.h"
#include "Addition.h"
#include "Constante.h"
#include "Expression.h"

using namespace std;

Addition::Addition(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
{

}

Addition::~Addition()
{

Addition::Addition(const Addition& other):Operateur(other)
{
    //copy ctor
    //this->_operandeDroite = other._operandeDroite;
    //this->_operandeGauche = other._operandeGauche;
}

void Addition::afficher(ostream &os) const
{

    os << "( ";
    _operandeGauche->afficher(os);
    os << " + ";
    _operandeDroite->afficher(os);
    os << " )";

}

void Addition::afficherNPI(ostream &os) const
{
    os << "( ";
    _operandeGauche->afficher(os);
    os << " ";
    _operandeDroite->afficher(os);
    os << " + ";
    os << " )";
}

float Addition::calculer()
{
   return _operandeGauche->calculer() + _operandeDroite->calculer();

}


Expression* Addition::simplifier()
{
    Constante *New_cte; // Creation d'un pointeur de type Constante
    Expression *New_exp; // Creation d'un pointeur de type Expression
    float result=0;

        if (typeid(*_operandeGauche) == typeid(Variable)) // cas de l'operande_Gauche = Variable
            {
                if (typeid(*_operandeDroite) == typeid(Variable))
                    {
                        //cout << "var & var "<< *this<< endl; // Pour debug
                        return this; // On renvoi l'expression non simplifiable car contient 2 variables
                    }
                else if (typeid(*_operandeDroite) == typeid(Constante))
                    {
                        //cout << "var & cte "<< *this<< endl; // Pour debug
                        return this; // On renvoi l'expression non simplifiable car contient 1 variable et 1 constante
                    }
                else // cas de l'operande_Droite = Expression
                {
                    _operandeDroite=_operandeDroite->simplifier(); // Simplification de l'op�rande droite dans le cas d'une expression
                    Addition add_res(_operandeGauche,_operandeDroite); // Recreation d'une nouvelle addition avec operande droite simplifiee
                    New_exp=new Addition(add_res); // Affectation au pointeur de la nouvelle expression pour recuperation par le main
                    //cout << "var & exp "<< *New_exp<< endl; // Pour debug
                    return New_exp;
                }
            }

        else if (typeid(*_operandeGauche) == typeid(Constante))
            {
                if (typeid(*_operandeDroite) == typeid(Variable))
                    {
                        // cout << "Cte & var "<< *this<< endl; // Pour debug
                        return this; // On renvoi l'expression non simplifiable car contient 2 variables
                    }
                else if (typeid(*_operandeDroite) == typeid(Constante))
                    {
                    Addition add_res(_operandeGauche,_operandeDroite);
                    result=add_res.calculer();
                    New_cte=new Constante(result);
                    //cout << "cte & cte "<< *New_cte << endl; // Pour debug
                    return New_cte;
                    }
                else // cas de l'operande_Droite = expression quand operande_Gauche = constante
                {
                    _operandeDroite=_operandeDroite->simplifier();
                    Addition add_res(_operandeGauche,_operandeDroite);
                    if (typeid(*_operandeDroite) != typeid(Constante))
                        {
                            //cout << "cte & exp apres simplification "<< *this<< endl; // Pour debug
                            return this;
                        }
                    else
                        {
                            result=add_res.calculer();
                            New_cte=new Constante(result);
                            //cout << "cte & cte apres simplification "<< *New_cte<< endl; // Pour debug
                            return New_cte;
                        }
                }
            }
        else // cas de l'operande_Gauche = Expression
        {
            _operandeGauche=_operandeGauche->simplifier();
            Addition add_res(_operandeGauche,_operandeDroite);
            if (typeid(*_operandeGauche) != typeid(Constante))
                {
                    if (typeid(*_operandeDroite) == typeid(Variable))
                        {
                            //cout << "exp apres simplification & var "<< *this << endl; // Pour debug
                            return this;
                        }
                    else if (typeid(*_operandeDroite) == typeid(Constante))
                        {
                            New_exp=new Addition(add_res);
                            //cout << "exp apres simplification & cte "<< *New_exp << endl; // Pour debug
                            return New_exp;
                        }
                    else // quand operande_droite = Expression
                        {
                            _operandeDroite=_operandeDroite->simplifier();
                            Addition add_res(_operandeGauche,_operandeDroite);
                            New_exp=new Addition(add_res);
                            //cout << "exp apres simplification & exp apres simplification "<< *New_exp << endl; // Pour debug
                            return New_exp;
                        }
                }
            else // cas de l'operande_Gauche apres simplification = constante
                {
                    if (typeid(*_operandeDroite) == typeid(Variable))
                        {
                            //cout << "cte apres simplification & var "<< *this<< endl; // Pour debug
                            return this;
                        }
                    else if (typeid(*_operandeDroite) == typeid(Constante))
                        {
                            result=add_res.calculer();
                            New_cte=new Constante(result);
                            //cout << "cte apres simplification & cte "<< *New_cte<< endl; // Pour debug
                            return New_cte;
                        }
                    else // cas de l'operande_Droite = Expression
                        {
                            _operandeDroite=_operandeDroite->simplifier();
                            Addition add_res(_operandeGauche,_operandeDroite);
                            if (typeid(*_operandeDroite) != typeid(Constante))
                                {
                                    New_exp=new Addition(add_res);
                                    //cout << "cte apres simplification & exp apres simplification "<< *New_exp<< endl; // Pour debug
                                    return New_exp;
                                }
                            else // Cas de l'operande_Droite apres simplification = Constante
                            {
                                result=add_res.calculer();
                                New_cte=new Constante(result);
                                //cout << "cte apres simplification & cte apres simplification "<< *New_cte<< endl; // Pour debug
                                return New_cte;
                            }
                        }
                }
        }

}

ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
