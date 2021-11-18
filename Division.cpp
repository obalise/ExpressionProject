#include <iostream>
#include "Variable.h"
#include "Division.h"
#include "Constante.h"

Division::Division(Expression* a, Expression* b) : _operandeGauche(a) , _operandeDroite(b){ /*cout <<  "Division" << endl;*/ }

Division::~Division()
{
    //cout << endl <<  "Destruction Division" << endl;
}

Division::Division(const Division& other):Operateur(other)
{
    //copy ctor
}

void Division::afficher(ostream &os) const
{

    os << "(";
    _operandeGauche->afficher(os);
    os << "/";
    _operandeDroite->afficher(os);
    os << ")";

}

void Division::afficherNPI(ostream &os) const
{
    _operandeGauche->afficherNPI(os);
    _operandeDroite->afficher(os);
    os << "/";
    os << endl;
}

float Division::calculer()
{
    return _operandeGauche->calculer()/_operandeDroite->calculer();
}


Expression* Division::simplifier()
{
    Expression *temp;
    Constante div=0;
        if ((typeid(*_operandeGauche) == typeid(Variable)) || (typeid(*_operandeDroite) == typeid(Variable)))
            {
                //cout<< "OpD ou OpD=Var "<<endl;
                return this;
            }
            else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                {
                    //cout<< "OpG & D=Cte :"<<endl;
                    Division res2(_operandeGauche,_operandeDroite);
                    div=res2.calculer();
                }
                else if ((typeid(*_operandeGauche) == typeid(Constante)) && (typeid(*_operandeDroite) != typeid(Constante)))
                    {
                        //cout<< "OpG=Cte & OPD=Exp :"<<endl;
                        Division res2(_operandeGauche,_operandeDroite->simplifier());
                        div=res2.calculer();
                    }
                    else if ((typeid(*_operandeGauche) != typeid(Constante)) && (typeid(*_operandeDroite) == typeid(Constante)))
                    {
                        //cout<< "OpG=Exp & OpD=Cte :"<<endl;
                        Division res2(_operandeGauche->simplifier(),_operandeDroite);
                        div=res2.calculer();
                    }
                        else
                            {
                                //cout<< "OpG=Exp & OPD=Exp :"<<endl;
                                Division res2(_operandeGauche->simplifier(),_operandeDroite->simplifier());
                                div=res2.calculer();
                            }

    temp=&div;

    cout<< "Resultat fct div simplifier final="<<div<<endl;
    cout<< "Resultat fct addr Tempo div simplifier final="<<&temp<<endl;
    cout<< "Resultat fct contenu Tempo div simplifier final="<<temp<<endl;
    return this;
}

ostream &operator<<( ostream &os, const Division& op)
{
    op.afficher(os);
    return os;
}
