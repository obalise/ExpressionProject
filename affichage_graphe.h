#ifndef AFFICHAGE_GRAPHE_H
#define AFFICHAGE_GRAPHE_H

#include <QDialog>

namespace Ui {
class Affichage_graphe;
}

class Affichage_graphe : public QDialog
{
    Q_OBJECT

public:
    explicit Affichage_graphe(QWidget *parent = nullptr);
    ~Affichage_graphe();

private:
    Ui::Affichage_graphe *ui;
};

#endif // AFFICHAGE_GRAPHE_H
