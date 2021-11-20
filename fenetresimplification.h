#ifndef FENETRESIMPLIFICATION_H
#define FENETRESIMPLIFICATION_H

#include <QMainWindow>

namespace Ui {
class FenetreSimplification;
}

class FenetreSimplification : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenetreSimplification(QWidget *parent = nullptr);
    ~FenetreSimplification();

private:
    Ui::FenetreSimplification *ui;
};

#endif // FENETRESIMPLIFICATION_H
