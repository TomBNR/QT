#ifndef DIETETIQUE_H
#define DIETETIQUE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Dietetique; }
QT_END_NAMESPACE

class Dietetique : public QWidget
{
    Q_OBJECT

public:
    Dietetique(QWidget *parent = nullptr);
    ~Dietetique();

private slots:
    void on_pushButtonSuite_clicked();

    void on_pushButtonLorentz_clicked();

private:
    Ui::Dietetique *ui;

    void afficherInfos();
    double poids;
    double taille;
    QString nom;
    QString prenom;
    int age;
    static const int NBIMC=6;
    static const int NBCORPULENCE=7;
};
#endif // DIETETIQUE_H
