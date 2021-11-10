#include <iostream>

#include "Addition.h"

using namespace std;

//Addition::Addition(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
//{
    //cout <<  "Addition " << endl;
//}

//Addition::~Addition()
//{
    //cout <<  "Destruction Addition" << endl;
//}

Addition* Addition::addition_= nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Addition *Addition::GetInstance(Expression& a, Expression& b)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(addition_==nullptr){
        addition_ = new Addition(&a, &b);
    }
    return addition_;
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

ostream &operator<<(ostream &os, const Addition& op)
{
    op.afficher(os);
    return os;
}
