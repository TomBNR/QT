#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BoutonLinux_clicked()
{
    ui->ZoneTextEvt->append("Bouton Linux Cliqué");
}

void MainWindow::on_BouttonWindows_clicked()
{
    ui->ZoneTextEvt->append("Bouton Windows Cliqué");
}

void MainWindow::on_BouttonOsXLion_clicked()
{
    ui->ZoneTextEvt->append("Bouton OS X Lion Cliqué");
}

void MainWindow::on_RadioWindows_clicked()
{

    ui->ZoneTextEvt->append("Radio Windows Cliqué");
}

void MainWindow::on_RadioOsXLion_clicked()
{

    ui->ZoneTextEvt->append("Radio OS X Lion Cliqué");
}

void MainWindow::on_RadioLinux_clicked()
{

    ui->ZoneTextEvt->append("Radio LINUX Cliqué");
}

void MainWindow::on_CheckWindows_stateChanged(int arg1)
{
    if(ui->CheckWindows->isChecked()){
        ui->ZoneTextEvt->append("Etat Check Windows ON");
    }else{
        ui->ZoneTextEvt->append("Etat Check Windows OFF");
    }

}

void MainWindow::on_CheckOsXLion_stateChanged(int arg1)
{
    if(ui->CheckOsXLion->isChecked()){
        ui->ZoneTextEvt->append("Etat Check OS X Lion ON");
    }else{
        ui->ZoneTextEvt->append("Etat Check OS X Lion OFF");
    }
}

void MainWindow::on_CheckLinux_stateChanged(int arg1)
{
   /* if(ui->CheckLinux>isChecked()){
        ui->ZoneTextEvt->append("Etat Check Linux ON");
    }else{
        ui->ZoneTextEvt->append("Etat Check Linux OFF");
    }*/
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->ZoneTextEvt->append(arg1);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->ZoneTextEvt->append("ComboBox : "+arg1);
}

void MainWindow::on_actionJavaScript_triggered()
{
    ui->ZoneTextEvt->append("Menu Web>JS cliqué");
}

void MainWindow::on_actionPHP_triggered()
{
    ui->ZoneTextEvt->append("Menu Web>PHP cliqué");
}

void MainWindow::on_actionC_2_triggered()
{
    ui->ZoneTextEvt->append("Menu C++ cliqué");
}

void MainWindow::on_Menu_triggered()
{
    ui->ZoneTextEvt->append("Menu JAVA cliqué");
}

void MainWindow::on_actionC_triggered()
{
    ui->ZoneTextEvt->append("Menu C cliqué");
}
