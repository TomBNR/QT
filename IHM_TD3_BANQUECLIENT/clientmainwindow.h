#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QBuffer>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientMainWindow; }
QT_END_NAMESPACE

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

private slots:
    void on_pushButtonConnexion_clicked();

    void on_pushButtonNumeroCompte_clicked();

    void on_pushButtonEnvoi_clicked();
    void onQtcpSocket_connected();
    void onQtcpSocket_disconnected();
    void onQtcpSocket_error(QAbstractSocket::SocketError socketError);
    void onQtcpSocket_readyRead();

private:
    Ui::ClientMainWindow *ui;
    QTcpSocket *socketClientBanque;
};
#endif // CLIENTMAINWINDOW_H
