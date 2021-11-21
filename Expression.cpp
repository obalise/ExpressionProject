#include <iostream>

#include "Expression.h"

using namespace std;

Expression::Expression()
{

}

Expression::~Expression()
{

ostream &operator<<( ostream &os, const Expression& exp)
{
    exp.afficher(os);
    return os;
}
