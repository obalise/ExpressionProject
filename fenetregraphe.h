#ifndef FENETREGRAPHE_H
#define FENETREGRAPHE_H

#include <QWidget>

namespace Ui {
class FenetreGraphe;
}

class FenetreGraphe : public QWidget
{
    Q_OBJECT

public:
    explicit FenetreGraphe(QWidget *parent = nullptr);
    ~FenetreGraphe();

private:
    Ui::FenetreGraphe *ui;
};

#endif // FENETREGRAPHE_H
