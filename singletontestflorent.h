#ifndef SINGLETONTESTFLORENT_H
#define SINGLETONTESTFLORENT_H


class SingletonTestFlorent
{
public:
    //Pas de clonage de singleton, je rends impossible d'utiliseur un constructeur de recopie
    SingletonTestFlorent(SingletonTestFlorent &other) = delete;

    //Pas de possibilité de réassigner un singleton
    void operator=(const SingletonTestFlorent &) = delete;

    //Fonction statique gardant "en mémoire"
    static SingletonTestFlorent& PasserExpression(){
        static SingletonTestFlorent instanceUniqueExpression;
        return instanceUniqueExpression;
    }

private:
    //Ce n'est pas juste une déclaration de mon constructeur, c'est aussi une définition
    SingletonTestFlorent(){}

};

#endif // SINGLETONTESTFLORENT_H
