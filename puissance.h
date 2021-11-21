#ifndef PUISSANCE_H
#define PUISSANCE_H


#include <iostream>

#include "Operateur.h"

using namespace std;

class Puissance : public Operateur
{
public:
    Puissance(Expression* a, Expression* b);
    virtual ~Puissance();
    Puissance(const Puissance& other);

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;
    Expression* simplifier() override;


protected:

private:

    Expression* _operandeGauche;
    Expression* _operandeDroite;

};

ostream &operator<<(ostream &os, const Puissance& op);

#endif // PUISSANCE_H
