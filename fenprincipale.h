#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QList>

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
    //explicit FenPrincipale(QWidget *parent = nullptr);
    FenPrincipale(int x, int y);
    Expression* getExpression();
    void setExpression(Expression*);
    //Expression* _monExpression;
    SaisieExpressionIHM *saisieExpressionGraphique = 0;

    private:
    QString *fileName;
    QTextEdit *textEdit;
    QString mot;
    QString texte;
    QString curFile;
    QLabel* imageLabel;
    Expression* _monExpression;

    public slots:
    bool sauvegarder();
    bool saveFile(const QString &fileName);
    void charger();
    void saisie();
    void affichageNC();
    void affichageNPI();
    void affichageVal();
    void affichageGraph();
    void affichageSimplification();


    signals:

};

#endif // FENPRINCIPALE_H
