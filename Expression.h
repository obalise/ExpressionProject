#ifndef EXPRESSION_H
#define EXPRESSION_H

#define ABSTRACT_CLASS

#include <iostream>
#include <string>
#include "Singleton.h"

using namespace std;


class Expression
{
    public:
        Expression();
        virtual ~Expression();
        virtual float calculer() = 0;
        virtual Expression* simplifier() = 0;
        virtual void afficher(ostream &os) const = 0;
        virtual void afficherNPI(ostream &os) const = 0;

    protected:


    private:

};

ostream &operator<<(ostream &os, const Expression& exp);


#endif // EXPRESSION_H
