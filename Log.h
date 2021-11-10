#ifndef LOG_H
#define LOG_H

#include <iostream>
#include "Opunin.h"

class Log
{
    public:
        Log(Expression* a, Expression* b);
        virtual ~Log();
        Log(const Log& other);

        float calculer () override;
        void afficher(ostream &os) const override;
        void afficherNPI(ostream &os) const override;


    protected:

    private:
        Expression* _operandeGauche;
        Expression* _operandeDroite;
};
 ostreamm &operator << (ostream &os, const Log& op);
#endif // LOG_H
