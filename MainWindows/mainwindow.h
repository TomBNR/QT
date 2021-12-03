#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BoutonLinux_clicked();

    void on_BouttonWindows_clicked();

    void on_BouttonOsXLion_clicked();

    void on_RadioWindows_clicked();

    void on_RadioOsXLion_clicked();

    void on_RadioLinux_clicked();

    void on_CheckWindows_stateChanged(int arg1);

    void on_CheckOsXLion_stateChanged(int arg1);

    void on_CheckLinux_stateChanged(int arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_actionJavaScript_triggered();

    void on_actionPHP_triggered();

    void on_actionC_2_triggered();

    void on_Menu_triggered();

    void on_actionC_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
