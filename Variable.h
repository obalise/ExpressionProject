#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <map>

#include "Expression.h"

using namespace std;

class Variable : public Expression
{
public:
    Variable(char _variable);
    virtual ~Variable();
    Variable(const Variable& other);
    void afficherNPI(ostream &os) const override;
    float calculer() override;
    void afficher(ostream &os) const override;
    Expression* simplifier() override;
    float attribution();
    void afficherVariable(char var);
    float getValeur(char var);
    void afficherTableSymboles();

    float GetVariable()
    {
        return _variable;
    }
    void SetVariable(char val)
    {
        _variable = val;
    }

protected:

private:

    char _variable;
    float _valeur;
    map <char, float> _symbole;
};

ostream &operator<<(ostream &os, const Variable& c1);

#endif // VARIABLE_H