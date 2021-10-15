#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <iostream>

#include "Operateur.h"


class Multiplication : public Operateur
{
public:
    Multiplication(Expression* a, Expression* b);
    virtual ~Multiplication();
    Multiplication(const Multiplication& other);

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;


protected:

private:

    Expression* _operandeGauche;
    Expression* _operandeDroite;
};

ostream &operator<<(ostream &os, const Multiplication& op);

#endif // MULTIPLICATION_H
