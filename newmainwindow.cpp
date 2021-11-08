#include "newmainwindow.h"
#include "ui_newmainwindow.h"

NewMainWindow::NewMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewMainWindow)
{
    ui->setupUi(this);
}

NewMainWindow::~NewMainWindow()
{
    delete ui;
}


