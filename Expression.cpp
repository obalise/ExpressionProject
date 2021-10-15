#include <iostream>

#include "Expression.h"

using namespace std;

Expression::Expression()
{
    //cout << "Expression" << endl;
}

Expression::~Expression()
{
    cout << "Destruction Expression" << endl;
}

Expression::Expression(const Expression& other)
{
    //copy ctor
}

void Expression::afficher(ostream &os) const
{

}

void Expression::afficherNPI(ostream &os) const
{

}
ostream &operator<<( ostream &os, const Expression& exp)
{
    exp.afficher(os);
    return os;
}

