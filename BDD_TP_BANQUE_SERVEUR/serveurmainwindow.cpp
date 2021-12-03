#include "serveurmainwindow.h"
#include "ui_serveurmainwindow.h"

ServeurMainWindow::ServeurMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ServeurMainWindow)
{
    ui->setupUi(this);
    leServeur = new ServeurBanque;
    leServeur->Start();
}

ServeurMainWindow::~ServeurMainWindow()
{
    delete ui;
}

