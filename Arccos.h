#ifndef ARCCOS_H
#define ARCCOS_H
#include <cmath>
#include "OperateurUnaire.h"

class Arccos : public OperateurUnaire
{
    public:
        Arccos(Expression* a);
        virtual ~Arccos();
        Arcsin(const Arccos& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const Arccos& op);

#endif // ARCCOS_H
