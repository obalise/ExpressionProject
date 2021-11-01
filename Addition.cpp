#include <iostream>

#include "Addition.h"
#include "Constante.h"
#include "Expression.h"

using namespace std;

Addition::Addition(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
{
    //cout <<  "Addition " << endl;
}

Addition::~Addition()
{
    //cout <<  "Destruction Addition" << endl;
}

Addition::Addition(const Addition& other)
{
    //copy ctor
}

void Addition::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "+";
    _operandeDroite->afficher(os);
    os << ")";

}

void Addition::afficherNPI(ostream &os) const
{
    _operandeGauche->afficher(os);
    _operandeDroite->afficher(os);
    os << "+";
    //os << endl;

}

float Addition::calculer()
{
   return _operandeGauche->calculer()+ _operandeDroite->calculer();
}


Expression* Addition::simplifier()
{
    float add=0;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                Addition res2(_operandeGauche,_operandeDroite);
                add=res2.calculer();
            }
            else
            {
                Addition res2(_operandeGauche,_operandeDroite->simplifier());
                add=res2.calculer();
            }
        }
        else
        {
            Addition res2(_operandeGauche->simplifier(),_operandeDroite);
            add=res2.calculer();
        }

    cout<< "Resultat fct add simplifier add final="<<add<<endl;
    return this;

}


ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
