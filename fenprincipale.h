#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QtWidgets>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
    public:
    //explicit FenPrincipale(QWidget *parent = nullptr);
    FenPrincipale(int x, int y);

    public slots:
    void saisie();

    signals:

};

#endif // FENPRINCIPALE_H
