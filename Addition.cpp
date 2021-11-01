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

/*Expression* Addition::simplifier()
{
    Expression *res2;
    res2=(_operandeGauche->simplifier(),_operandeDroite->simplifier());
    res2.afficher(cout);
    cout<< "Resultat fct add simplifier res2="<<res2<<endl;
 return res2;
}*/

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

Expression* Addition::simplifier()
{
    float res1=0;
    Expression *E;
        if (typeid(*_operandeGauche) != typeid(Constante))
            _operandeGauche->simplifier();
        else
            if (typeid(*_operandeDroite) != typeid(Constante))
                _operandeDroite->simplifier();
            else
            {
                res1=_operandeGauche->calculer()+_operandeDroite->calculer();
                E=new Constante(res1);
            }
    cout<< "Resultat fct add simplifier res1="<<res1<<endl;
    return E;
}

/*Expression* Addition::simplifier()
{
    float res1=0;
    Expression *E;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            cout<<"If Addition cte gauche"<<endl;
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                res1=_operandeGauche->calculer()+_operandeDroite->calculer();
                cout<<"If Addition cte droite"<<endl;
                E= new Constante(res1);
            }
            else
            {
                cout<<"Else Addition droite"<<endl;
                E=new Expression(_operandeDroite->simplifier());
            }
        }
        else
        {
            cout<<"Else Addition gauche"<<endl;
            _operandeGauche->simplifier();
        }

    cout<< "Resultat fct add simplifier res1="<<res1<<endl;
    return E;
}*/

ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
