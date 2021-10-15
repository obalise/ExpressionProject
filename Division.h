#ifndef DIVISION_H
#define DIVISION_H

#include <iostream>

#include "Operateur.h"


class Division : public Operateur
{
public:
    Division(Expression* a, Expression* b);
    virtual ~Division();
    Division(const Division& other);

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;

protected:

private:

    Expression* _operandeGauche;
    Expression* _operandeDroite;
};

ostream &operator<<(ostream &os, const Division& op);

#endif // DIVISION_H
