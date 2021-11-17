#pragma once

#include <QMainWindow>

namespace Ui {
class SaisieExpressionGraphe;
}

class SaisieExpressionGraphe : public QMainWindow
{
    Q_OBJECT

public:
    explicit SaisieExpressionGraphe(QWidget *parent = nullptr);
    ~SaisieExpressionGraphe();

private:
    Ui::SaisieExpressionGraphe *ui;
};

