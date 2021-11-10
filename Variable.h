#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <map>

#include "Expression.h"

using namespace std;

extern float vGlobValVar;

class Variable : public Expression
{
public:
    Variable(char _variable);
    virtual ~Variable();
    Variable(const Variable& other);

    //void afficher() override;
    void afficherNPI(ostream &os) const override;
    float calculer() override;
   // float calculer(float val) override;
    void afficher(ostream &os) const override;
    float attribution();
    void attribution(float valeur);

    char GetVariable()
    {
        return _variable;
    }
    void SetVariable(char val)
    {
        _variable = val;
    }

    float GetValeur()
    {
        return _valeur;
    }
    void SetValeur(float val)
    {
        _valeur = val;
    }

protected:

private:

    char _variable;
    float _valeur;
    map <char, float> _symbole;
};


ostream &operator<<(ostream &os, const Variable& c1);

#endif // VARIABLE_H
