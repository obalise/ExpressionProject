#include <iostream> 
#include "Addition.h" 
#include "Soustraction.h" 
#include "Division.h" 
#include "Multiplication.h" 
#include "Constante.h" 
#include "Operateur.h" 
#include "Expression.h" 
#include "Simplifier.h" 
#include <ctype.h> 
#include <typeinfo> 
 
using namespace std; 
 
Simplifier::Simplifier(char c,Expression *a,Expression *b): _operateur(c), _operandeGauche(a), _operandeDroite(b) 
{ 
    cout << "Construction Simplifier" << endl; 
        float resultat; 
    if (typeid(*a) == typeid(Constante)) 
        { 
       if (typeid(*b) == typeid(Constante)) 
        { 
 
           if (c=='+') 
           { 
                Addition add1(a,b); 
                resultat=add1.calculer(); 
           } 
           if (c=='-') 
           { 
                Soustraction sous1(a,b); 
                resultat=sous1.calculer(); 
           } 
            if (c=='*') 
           { 
                Multiplication mult1(a,b); 
                resultat=mult1.calculer(); 
           } 
            if (c=='/') 
           { 
                Division div1(a,b); 
                resultat=div1.calculer(); 
           } 
        } 
    } 
    cout << "final = " << resultat << endl; 
    _valeur=resultat; 
} 
 
Simplifier::Simplifier() 
{ 
} 
 
void Simplifier::afficherNPI(ostream &os) const 
{ 
    _operandeGauche->afficherNPI(os); 
    _operandeDroite->afficher(os); 
    os << "*"; 
    //os << endl; 
} 
 
float Simplifier::calculer() 
{ 
    return _operandeGauche->calculer()*_operandeDroite->calculer(); 
} 
 
 
void Simplifier::afficher(ostream &os ) const 
{ 
    os << _valeur; 
} 
 
Simplifier::~Simplifier() 
{ 
    cout << "Destruction Simplifier" << endl; 
} 
