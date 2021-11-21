#ifndef OPPOSE_H
#define OPPOSE_H
#include "OperateurUnaire.h"
#include <iostream>

usin namespace std;

class Oppose : public OperateurUniare
{
    public:
        Oppose();
        virtual ~Oppose();
        void afficher (ostream &os) const override;
        void afficherNPI (ostream &os) const override;
        float calculer ();
        expression* simplifier() override;

    protected:

    private:
        Expression* operateurUnique;
};

#endif // OPPOSE_H
