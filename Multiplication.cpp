#include <iostream>

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
    float res=0;
    Expression *E;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            cout<<"If Multi Cte gauche"<<endl;
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                res=_operandeGauche->calculer()*_operandeDroite->calculer();
                cout<<"If Multi Cte droite"<<endl;
                E= new Constante(res);
            }
            else
            {
                cout<<"Else Multi droite"<<endl;
                _operandeDroite->simplifier();
            }
        }
        else
        {
            cout<<"Else Multi gauche"<<endl;
            _operandeGauche->simplifier();
        }

    cout<< "Resultat fct Multi simplifier res ="<<res<<endl;
    return E;

}

ostream &operator<<( ostream &os, const Multiplication& op)
{
    op.afficher(os);
    return os;
}
