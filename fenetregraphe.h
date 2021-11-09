#ifndef FENETREGRAPHE_H
#define FENETREGRAPHE_H

#include <QMainWindow>

namespace Ui {
class NewMainWindow;
}

class NewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewMainWindow(QWidget *parent = nullptr);
    ~NewMainWindow();

private:
    Ui::NewMainWindow *ui;
};

#endif // FENETREGRAPHE_H


//Permet d'avoir la nouvelle fenêtre pour afficher notre courbe
