#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#define NBTOUCHES 16

QT_BEGIN_NAMESPACE
namespace Ui { class Calculatrice; }
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();

public slots:
    void onQPushButtonClicked();

private:
    Ui::Calculatrice *ui;
    QLineEdit *afficheur;
    QPushButton *touches[16];
    QGridLayout *grille;
    const QString tableDesSymboles[16]={"0","1","2","3","4","5","6","7","8","9","c","=","/","*","-","+"};
};
#endif // CALCULATRICE_H
