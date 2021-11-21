#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>
#include "Addition.h"

#include "Expression.h"
#include "saisieexpressionIHM.h"

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
    public:
    FenPrincipale(int x, int y);
    Expression* getExpression();
    void setExpression(Expression*);
    SaisieExpressionIHM *saisieExpressionGraphique = 0; //Nous aurons besoin de ce pointeur pour créer notre fenêtre de Saisie de l'expression

    private:
    QString *fileName; // const QString &name, nom du fichier à charger/sauvegarder
    QTextEdit *textEdit; // Pointeur de widget qui permet d'éditer et d'afficher des informations.
    QString mot; // Buffer de flux(fichier texte)
    QString curFile; // const QString &dir = QString(); chemin ou sauvegarder le fichier + nom du fichier
    QString texte; // Buffer de texte
    QString _affichageNC; // gestion affichageNC
    QString _affichageNPI; // gestion affichageNPI
    QString _affichageCalcul; // gestion affichage Calcul


    Expression* _monExpression; // Pointeur pour acceder aux objets Expression.
    Addition *add1, *add2, *add3; // Pointeur pour manpipuler des additions
    Soustraction *sous1, *sous2, *sous3; // Pointeur pour manpipuler des additions
    Multiplication *mux1, *mux2, *mux3; // Pointeur pour manpipuler des additions
    Division *div1, *div2, *div3; // Pointeur pour manpipuler des additions

    public slots:
    bool sauvegarderFichier();
    bool saveFile(const QString &fileName);
    void charger();
    bool sauvegarderExpression();
    void saisie();
    void saisieGraphique();
    void affichageNC();
    void affichageNPI();
    void affichageVal();
    void affichageGraph();
    void affichageSimplification();


    signals:

};

#endif // FENPRINCIPALE_H
