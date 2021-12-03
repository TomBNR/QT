#ifndef DIETETIQUE_H
#define DIETETIQUE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class dietetique; }
QT_END_NAMESPACE

class dietetique : public QMainWindow
{
    Q_OBJECT

public:
    dietetique(QWidget *parent = nullptr);
    ~dietetique();

private slots:
    void on_pushButtonSuite_clicked();

    void on_pushButtonLorentz_clicked();

private:
    Ui::dietetique *ui;
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
