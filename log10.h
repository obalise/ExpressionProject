#ifndef LOG10_H
#define LOG10_H

#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class Log10 : public OperateurUnaire
{
    public:
        Log10(Expression* a);
        virtual ~Log10();
        Log10 (const Log10& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

#endif // LOG10_H
