#ifndef SERVEURMAINWINDOW_H
#define SERVEURMAINWINDOW_H

#include <QMainWindow>
#include <serveurbanque.h>
QT_BEGIN_NAMESPACE
namespace Ui { class ServeurMainWindow; }
QT_END_NAMESPACE

class ServeurMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ServeurMainWindow(QWidget *parent = nullptr);
    ~ServeurMainWindow();

private:
    Ui::ServeurMainWindow *ui;
    ServeurBanque*leServeur;

};
#endif // SERVEURMAINWINDOW_H
