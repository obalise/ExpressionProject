#ifndef ADDITION_H
#define ADDITION_H

#include <iostream>

#include "Operateur.h"

using namespace std;

class Addition : public Operateur
{
public:
    //Addition(Expression* a, Expression* b);
    //virtual ~Addition();
    //Addition(const Addition& other);

    /**
     * Singletons should not be cloneable.
     */
    Addition(Addition &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Addition &) = delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */

    static Addition *GetInstance(Expression& a, Expression& b);
    /**
     * Finally, any singleton should define some business logic, which can be
     * executed on its instance.
     */

    float calculer() override;
    void afficher(ostream &os) const override;
    void afficherNPI(ostream &os) const override;

    Expression* opG() const{
        return _operandeGauche;
    }

    Expression* opD() const{
        return _operandeDroite;
    }


protected:

    Addition(Expression* a, Expression* b) : _operandeGauche(a), _operandeDroite(b)
    {
        //cout <<  "Addition " << endl;
    }

    static Addition* addition_;

    Expression* _operandeGauche;
    Expression* _operandeDroite;

private:

    //Expression* _operandeGauche;
    //Expression* _operandeDroite;

};

ostream &operator<<(ostream &os, const Addition& op);

#endif // ADDITION_H
