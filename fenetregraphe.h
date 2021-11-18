#ifndef FENETREGRAPHE_H
#define FENETREGRAPHE_H

#include <QMainWindow>

namespace Ui {
class NewMainWindow;
}

class FenetreGraphe : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreGraphe(QWidget *parent = nullptr);
    ~FenetreGraphe();

private:
    Ui::NewMainWindow *ui;
};

#endif // FENETREGRAPHE_H


//Permet d'avoir la nouvelle fenêtre pour afficher notre courbe
