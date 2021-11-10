#include <iostream>
#include "Addition.h"
#include "Soustraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Constante.h"
#include "Expression.h"
#include "Variable.h"

using namespace std;

int main()
{
Expression* test;

cout << "Hello world!" << endl;
Constante c1(10);
Constante c2(2);
Constante c3(4);
char x='a';
Variable toto(x);

Division div0(&c2,&c3);
Multiplication mult1(&c1,&c3);
Soustraction sous0(&mult1,&div0);

cout <<"Addr C2 = "<< &c2<<endl;
cout <<"Addr C3 = "<< &c3<<endl;
cout <<"&Test Sous = "<< &test<<endl;
//cout <<"&Test Sous = "<< *test<<endl;
test=sous0.simplifier();
sous0.afficher(cout);
cout <<"Sous0 = "<< &sous0<<endl;
cout <<"Test Sous = "<< test<<endl;
cout <<"&Test Sous = "<< &test<<endl;
cout <<"*Test Sous = "<< *test<<endl;
sous0.afficherNPI(cout);


return 0;
}
