#include <iostream>
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Constante.h"
#include "Expression.h"

using namespace std;

int main()
{
cout << "Hello world!" << endl;
<<<<<<< Updated upstream

=======
Expression * test;
>>>>>>> Stashed changes
Constante c1(5);
Constante c2(2);
Constante c3(4);

<<<<<<< Updated upstream
Multiplication mult1(&c1,&c2);

mult1.simplifier();

Addition add1(&mult1,&c3);
add1.simplifier();


=======

Soustraction sous0(&c3,&c2);
sous0.simplifier();


Multiplication mult1(&sous0,&c2);
mult1.simplifier();
Division div0(&c3,&c2);
Multiplication mult2(&sous0,&div0);
mult2.simplifier();

Addition add1(&sous0,&mult2);
test=add1.simplifier();
cout <<"="<< test;
/*Addition add2(&c3,&mult1);
add2.simplifier();*/
>>>>>>> Stashed changes
//
//Constante c5(-20);
//Constante c6(-3);
//Division div1(&c1,&c2);
//
//Addition add2(&c5,&c6);
//Multiplication mult1(&add1,&add2);
//float resultat = add1.calculer();
//float resultat2 = mult1.calculer();
//add1.afficher(cout);
//mult1.afficher(cout);
//cout <<"="<< resultat<< endl;
//cout <<"="<< resultat2<< endl;
//add1.afficherNPI(cout);
//cout <<"="<< resultat;
return 0;
}
