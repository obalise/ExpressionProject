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
   return _operandeGauche->calculer()+ _operandeDroite->calculer();
}


Expression* Addition::simplifier()
{
    Expression *temp;
    Constante add=0;
        if ((typeid(*_operandeGauche) == typeid(Variable)) || (typeid(*_operandeDroite) == typeid(Variable)))
            {
                //cout<< "OpD ou OpD=Var "<<endl;
                return this;
            }
            else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                {
                    //cout<< "OpG & D=Cte :"<<endl;
                    Addition res2(_operandeGauche,_operandeDroite);
                    add=res2.calculer();
                }
                else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) != typeid(Constante)))
                    {
                        //cout<< "OpG=Cte & OPD=Exp :"<<endl;
                        Addition res2(_operandeGauche,_operandeDroite->simplifier());
                        add=res2.calculer();
                    }
                    else if ((typeid(*_operandeGauche) != typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                    {
                        //cout<< "OpG=Exp & OpD=Cte :"<<endl;
                        Addition res2(_operandeGauche->simplifier(),_operandeDroite);
                        add=res2.calculer();
                    }
                        else
                            {
                                //cout<< "OpG=Exp & OPD=Exp :"<<endl;
                                Addition res2(_operandeGauche->simplifier(),_operandeDroite->simplifier());
                                add=res2.calculer();
                            }

    temp=&add;

    cout<< "Resultat fct add simplifier final="<<add<<endl;
    cout<< "Resultat fct addr Tempo add simplifier final="<<&temp<<endl;
    cout<< "Resultat fct contenu Tempo add simplifier final="<<temp<<endl;
    return this;
}

ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
