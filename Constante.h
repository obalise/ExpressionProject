#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>

#include "Expression.h"

using namespace std;

class Constante : public Expression
{
public:
    Constante(float _valeur);
    virtual ~Constante();
    Constante(const Constante& other);

    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;
    float calculer() override;
    Expression* simplifier() override;

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

    float _valeur;
};

ostream &operator<<(ostream &os, const Constante& c1);
#endif // CONSTANTE_H
