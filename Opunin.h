#ifndef OPUNIN_H
#define OPUNIN_H

#include "Expression.h"

using namespace std;

class Opunin : public Expression
{
    public:
        Opunin(Expression* a, Expression* b);
        virtual ~Opunin();
        opunin (const Opunin& other);

    protected:

    private:

        Expression* _operandeGauche;
        Expression* _oprenadedroite;
};

ostream &operator << (ostream &os, const Opunin& op);

#endif // OPUNIN_H
