#include <iostream>
#include "Variable.h"
#include "Multiplication.h"
#include "Constante.h"

Multiplication::Multiplication(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Multiplication" << endl;*/ }

Multiplication::~Multiplication()
{
    //cout << endl <<  "Destruction Multiplication" << endl;
}

Multiplication::Multiplication(const Multiplication& other)
{
    //copy ctor
}

void Multiplication::afficher(ostream &os) const
{
     _operandeGauche->afficher(os);
    os << "*";
    _operandeDroite->afficher(os);
}

void Multiplication::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "*";
    //os << endl;
}

float Multiplication::calculer()
{
    return _operandeGauche->calculer()*_operandeDroite->calculer();
}

Expression* Multiplication::simplifier()
{
    Expression *temp;
    Constante mult=0;
        if ((typeid(*_operandeGauche) == typeid(Variable)) || (typeid(*_operandeDroite) == typeid(Variable)))
            {
                //cout<< "OpD ou OpD=Var "<<endl;
                return this;
            }
            else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                {
                    //cout<< "OpG & D=Cte :"<<endl;
                    Multiplication res2(_operandeGauche,_operandeDroite);
                    mult=res2.calculer();
                }
                else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) != typeid(Constante)))
                    {
                        //cout<< "OpG=Cte & OPD=Exp :"<<endl;
                        Multiplication res2(_operandeGauche,_operandeDroite->simplifier());
                        mult=res2.calculer();
                    }
                    else if ((typeid(*_operandeGauche) != typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                    {
                        //cout<< "OpG=Exp & OpD=Cte :"<<endl;
                        Multiplication res2(_operandeGauche->simplifier(),_operandeDroite);
                        mult=res2.calculer();
                    }
                        else
                            {
                                //cout<< "OpG=Exp & OPD=Exp :"<<endl;
                                Multiplication res2(_operandeGauche->simplifier(),_operandeDroite->simplifier());
                                mult=res2.calculer();
                            }

    temp=&mult;

    cout<< "Resultat fct mult simplifier final="<<mult<<endl;
    cout<< "Resultat fct addr Tempo mult simplifier final="<<&temp<<endl;
    cout<< "Resultat fct contenu Tempo mult simplifier final="<<temp<<endl;
    return this;
}

ostream &operator<<( ostream &os, const Multiplication& op)
{
    op.afficher(os);
    return os;
}
