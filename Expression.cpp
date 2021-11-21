#include <iostream>

#include "Expression.h"

using namespace std;

Expression::Expression()
{
    //cout << "Expression" << endl;
}

Expression::~Expression()
{
    //cout << "Destruction Expression" << endl;
}

ostream &operator<<( ostream &os, const Expression& exp)
{
    exp.afficher(os);
    return os;
}
