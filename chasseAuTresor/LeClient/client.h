#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QWidget>
#include <QAbstractSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots :
    void on_pushButtonConnexion_clicked();
    void on_pushButtonOrdinateur_clicked();
    void on_pushButtonUtilisateur_clicked();
    void on_pushButtonArchitecture_clicked();
    void on_pushButtonOs_clicked();

    void onQTcpSocket_connected();
    void onQTcpSocket_disconnected();
    void onQTcpSocket_error(QAbstractSocket::SocketError socketError);
    void onQTcpSocket_hostFound();
    void onQTcpSocket_stateChanged(QAbstractSocket::SocketState socketState);
    void onQTcpSocket_aboutToclose();
    void onQTcpSocket_bytesWritten(qint64 bytes);
    void onQTcpSocket_readChannelFinished();
    void onQTcpSocket_readyRead();


private:
    Ui::Client *ui;
};
#endif // CLIENT_H
