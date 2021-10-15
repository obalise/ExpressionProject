#ifndef SOUSTRACTION_H
#define SOUSTRACTION_H

#include <iostream>

#include "Operateur.h"


class Soustraction : public Operateur
{
public:
    Soustraction(Expression* a, Expression* b);
    virtual ~Soustraction();
    Soustraction(const Soustraction& other);

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;

protected:

private:

    Expression* _operandeGauche;
    Expression* _operandeDroite;
};

ostream &operator<<(ostream &os, const Soustraction& op);

#endif // SOUSTRACTION_H
