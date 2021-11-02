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
    float mult=0;
        if (typeid(*_operandeGauche) == typeid(Constante))
        {
            if (typeid(*_operandeDroite) == typeid(Constante))
            {
                Multiplication res2(_operandeGauche,_operandeDroite);
                mult=res2.calculer();
            }
            else
            {
                Multiplication res2(_operandeGauche,_operandeDroite->simplifier());
                mult=res2.calculer();
            }
        }
        else
        {
            cout<<"Else Multi gauche"<<endl;
            _operandeGauche->simplifier();
        }

    cout<< "Resultat fct Multi simplifier res ="<<res<<endl;
    return E;
            Multiplication res2(_operandeGauche->simplifier(),_operandeDroite);
            mult=res2.calculer();
        }

    //cout<< "Resultat fct mult simplifier res final="<<mult<<endl;
    return this;
    }
}
ostream &operator<<( ostream &os, const Multiplication& op)
{
    op.afficher(os);
    return os;
}
