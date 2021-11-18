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
    Expression *temp;
    Constante sous=0;
        if ((typeid(*_operandeGauche) == typeid(Variable)) || (typeid(*_operandeDroite) == typeid(Variable)))
            {
                //cout<< "OpD ou OpD=Var "<<endl;
                return this;
            }
            else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                {
                    //cout<< "OpG & D=Cte :"<<endl;
                    Soustraction res2(_operandeGauche,_operandeDroite);
                    sous=res2.calculer();
                }
                else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) != typeid(Constante)))
                    {
                        //cout<< "OpG=Cte & OPD=Exp :"<<endl;
                        Soustraction res2(_operandeGauche,_operandeDroite->simplifier());
                        sous=res2.calculer();
                    }
                    else if ((typeid(*_operandeGauche) != typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                    {
                        //cout<< "OpG=Exp & OpD=Cte :"<<endl;
                        Soustraction res2(_operandeGauche->simplifier(),_operandeDroite);
                        sous=res2.calculer();
                    }
                        else
                            {
                                //cout<< "OpG=Exp & OPD=Exp :"<<endl;
                                Soustraction res2(_operandeGauche->simplifier(),_operandeDroite->simplifier());
                                sous=res2.calculer();
                            }

    temp=&sous;

    cout<< "Resultat fct sous simplifier final="<<sous<<endl;
    cout<< "Resultat fct addr Tempo sous simplifier final="<<&temp<<endl;
    cout<< "Resultat fct contenu Tempo sous simplifier final="<<temp<<endl;
    return this;
}

ostream &operator<<( ostream &os, const Soustraction& op)
{
    op.afficher(os);
    return os;
}
