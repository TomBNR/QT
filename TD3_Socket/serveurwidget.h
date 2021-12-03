#ifndef SERVEURWIDGET_H
#define SERVEURWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QProcess>
#include <QHostInfo>
#include <QList>
#include <QNetworkInterface>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurWidget; }
QT_END_NAMESPACE

class ServeurWidget : public QWidget
{
    Q_OBJECT

public:
    ServeurWidget(QWidget *parent = nullptr);
    ~ServeurWidget();

private slots:
    void onQTcpServer_newConnection();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_disconnected();
    void onQProcess_readyReadStandardOutput();

    void on_pushButtonServeur_clicked();

private:
    Ui::ServeurWidget *ui;
    QTcpServer *socketEcouteServeur;
    QList<QTcpSocket*> listeSocketDialogueClient;
    QList<QProcess*> listeProcess;
};
#endif // SERVEURWIDGET_H
