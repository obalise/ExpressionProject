#ifndef ADDITION_H
#define ADDITION_H

#include <iostream>

#include "Operateur.h"

using namespace std;

class Addition : public Operateur
{
public:
    Addition(Expression* a, Expression* b);
    virtual ~Addition();
    Addition(const Addition& other);

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;
    Expression* simplifier() override;


protected:


private:

    Expression* _operandeGauche;
    Expression* _operandeDroite;

};

ostream &operator<<(ostream &os, const Addition& op);

#endif // ADDITION_H
