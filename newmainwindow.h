#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

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

#endif // NEWMAINWINDOW_H
