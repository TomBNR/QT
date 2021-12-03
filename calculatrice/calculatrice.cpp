#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}


void Calculatrice::on_pushButton1_clicked()
{
    ui->lineEdit->insert("1");
}

void Calculatrice::on_pushButton2_clicked()
{
    ui->lineEdit->insert("2");
}

void Calculatrice::on_pushButton3_clicked()
{
    ui->lineEdit->insert("3");
}

void Calculatrice::on_pushButton4_clicked()
{
    ui->lineEdit->insert("4");
}

void Calculatrice::on_pushButton5_clicked()
{
    ui->lineEdit->insert("5");
}

void Calculatrice::on_pushButton6_clicked()
{
    ui->lineEdit->insert("6");
}

void Calculatrice::on_pushButton7_clicked()
{
    ui->lineEdit->insert("7");
}

void Calculatrice::on_pushButton8_clicked()
{
    ui->lineEdit->insert("8");
}

void Calculatrice::on_pushButton9_clicked()
{
    ui->lineEdit->insert("9");
}

void Calculatrice::on_pushButton0_clicked()
{
    ui->lineEdit->insert("0");
}

void Calculatrice::on_pushButtonPlus_clicked()
{
    ui->lineEdit->insert("+");
}

void Calculatrice::on_pushButtonMoins_clicked()
{
    ui->lineEdit->insert("-");
}

void Calculatrice::on_pushButtonMulti_clicked()
{
    ui->lineEdit->insert("*");
}

void Calculatrice::on_pushButtonDivision_clicked()
{
    ui->lineEdit->insert("/");
}

void Calculatrice::on_pushButtonClear_clicked()
{
    ui->lineEdit->clear();
}



void Calculatrice::on_pushButtonEgal_clicked()
{
    QScriptEngine script;
    ui->lineEdit->setText(script.evaluate(ui->lineEdit->text()).toString());
}
