#ifndef LOG_H
#define LOG_H


#include <iostream>
#include <cmath>
#include "OperateurUnaire.h"


class LogNeperien : public OperateurUnaire
{
    public:
        LogNeperien(Expression* a);
        virtual ~LogNeperien();
        LogNeperien (const LogNeperien& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;
        Expression* simplifier()override;

    protected:

    private:
        Expression* _operandeUnique;

};

ostream &operator<<(ostream &os, const LogNeperien & op);
#endif // LOG_H
