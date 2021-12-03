#ifndef SERVEUR_H
#define SERVEUR_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QGridLayout>
#include <QNetworkInterface>
#include <QThread>
#include <QRandomGenerator>
#include <QDateTime>
#include <QProcess>
#include <QHostInfo>

const int TAILLE = 20;

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurCrawler; }
QT_END_NAMESPACE

class ServeurCrawler : public QWidget
{
    Q_OBJECT

public:
    explicit ServeurCrawler(QWidget *parent = nullptr);
    ~ServeurCrawler();
private slots:
    void onQTcpServer_newConnection();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_disconnected();
    void on_pushButtonLancementServeur_clicked();

private:
    Ui::ServeurCrawler *ui;
    QTcpServer *socketEcoute;
    QList<QTcpSocket *> listeSocketsClient;
    QList<QPoint> listePositions;
    QPoint tresor;
    QGridLayout *grille;

    void EnvoyerDonnees(QTcpSocket *_client, QPoint _pt, QString _message);
    void AfficherGrille();
    void ViderGrille();
    QPoint DonnerPositionUnique();
    double CalculerDistance(QPoint _pos);
};
#endif // SERVEUR_H
