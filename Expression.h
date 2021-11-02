#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>

using namespace std;

class Expression
{
    public:
        Expression();
        virtual ~Expression();
        Expression(const Expression& other);

        virtual float calculer() = 0;
        virtual Expression* simplifier() = 0;
        virtual void afficher(ostream &os) const = 0;
        virtual void afficherNPI(ostream &os) const = 0;

    protected:

    private:

};

ostream &operator<<(ostream &os, const Expression& exp);

#endif // EXPRESSION_H
