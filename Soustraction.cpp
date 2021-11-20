#include <iostream>
#include "Variable.h"
#include "Soustraction.h"
#include "Constante.h"
#include "Expression.h"

Soustraction::Soustraction(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Soustraction" << endl;*/ }

Soustraction::~Soustraction()
{
    //cout << endl <<  "Destruction Soustraction" << endl;
}

Soustraction::Soustraction(const Soustraction& other):Operateur(other)
{
    //copy ctor
}

void Soustraction::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "-";
    _operandeDroite->afficher(os);
    os << ")"<<endl;

}

void Soustraction::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "-";
    //os << endl;
}

float Soustraction::calculer()
{
    return _operandeGauche->calculer()-_operandeDroite->calculer();
}

Expression* Soustraction::simplifier()
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
                    _operandeDroite=_operandeDroite->simplifier(); // Simplification de l'opérande droite dans le cas d'une expression
                    Soustraction sous_res(_operandeGauche,_operandeDroite); // Recreation d'une nouvelle addition avec operande droite simplifiee
                    New_exp=new Soustraction(sous_res); // Affectation au pointeur de la nouvelle expression pour recuperation par le main
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
                    Soustraction sous_res(_operandeGauche,_operandeDroite);
                    result=sous_res.calculer();
                    New_cte=new Constante(result);
                    //cout << "cte & cte "<< *New_cte << endl; // Pour debug
                    return New_cte;
                    }
                else // cas de l'operande_Droite = expression quand operande_Gauche = constante
                {
                    _operandeDroite=_operandeDroite->simplifier();
                    Soustraction sous_res(_operandeGauche,_operandeDroite);
                    if (typeid(*_operandeDroite) != typeid(Constante))
                        {
                            //cout << "cte & exp apres simplification "<< *this<< endl; // Pour debug
                            return this;
                        }
                    else
                        {
                            result=sous_res.calculer();
                            New_cte=new Constante(result);
                            //cout << "cte & cte apres simplification "<< *New_cte<< endl; // Pour debug
                            return New_cte;
                        }
                }
            }
        else // cas de l'operande_Gauche = Expression
        {
            _operandeGauche=_operandeGauche->simplifier();
            Soustraction sous_res(_operandeGauche,_operandeDroite);
            if (typeid(*_operandeGauche) != typeid(Constante))
                {
                    if (typeid(*_operandeDroite) == typeid(Variable))
                        {
                            //cout << "exp apres simplification & var "<< *this << endl; // Pour debug
                            return this;
                        }
                    else if (typeid(*_operandeDroite) == typeid(Constante))
                        {
                            New_exp=new Soustraction(sous_res);
                            //cout << "exp apres simplification & cte "<< *New_exp << endl; // Pour debug
                            return New_exp;
                        }
                    else // quand operande_droite = Expression
                        {
                            _operandeDroite=_operandeDroite->simplifier();
                            Soustraction sous_res(_operandeGauche,_operandeDroite);
                            New_exp=new Soustraction(sous_res);
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
                            result=sous_res.calculer();
                            New_cte=new Constante(result);
                            //cout << "cte apres simplification & cte "<< *New_cte<< endl; // Pour debug
                            return New_cte;
                        }
                    else // cas de l'operande_Droite = Expression
                        {
                            _operandeDroite=_operandeDroite->simplifier();
                            Soustraction sous_res(_operandeGauche,_operandeDroite);
                            if (typeid(*_operandeDroite) != typeid(Constante))
                                {
                                    New_exp=new Soustraction(sous_res);
                                    //cout << "cte apres simplification & exp apres simplification "<< *New_exp<< endl; // Pour debug
                                    return New_exp;
                                }
                            else // Cas de l'operande_Droite apres simplification = Constante
                            {
                                result=sous_res.calculer();
                                New_cte=new Constante(result);
                                //cout << "cte apres simplification & cte apres simplification "<< *New_cte<< endl; // Pour debug
                                return New_cte;
                            }
                        }
                }
        }

}

ostream &operator<<( ostream &os, const Soustraction& op)
{
    op.afficher(os);
    return os;
}
