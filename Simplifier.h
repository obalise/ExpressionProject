#ifndef SIMPLIFIER_H 
#define SIMPLIFIER_H 
 
#include <iostream> 
#include "Expression.h" 
#include "Operateur.h" 
 
class Simplifier : public Expression 
{ 
public: 
    Simplifier(); 
    Simplifier(char c,Expression* a,Expression *b); 
    virtual ~Simplifier(); 
    Simplifier(const Simplifier& other); 
 
    void afficherNPI(ostream &os) const override; 
    float calculer() override; 
    void afficher(ostream &os) const override; 
 
protected: 
 
 
private: 
    char _operateur; 
    Expression* _operandeGauche; 
    Expression* _operandeDroite; 
    float _valeur; 
}; 
 
#endif // SIMPLIFIER_H 
