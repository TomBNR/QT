#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonDessiner_clicked()
{
    QGraphicsScene *maScene=new QGraphicsScene();
    QGraphicsView *maVue=new QGraphicsView(this);
    // dimensionnement de la scene
    maScene->setSceneRect(0,0,400,300);
    QPolygon poly1;
    QGraphicsLineItem *Ligne;
    QGraphicsPolygonItem *PolyI;
    QGraphicsTextItem *monTexte;
    poly1.setPoints(4,10,10,100,20,50,50,30,100);

    ligne=new QGraphicsLineItem(0,0,400,300);
    polyI=new QGraphicsPolygonItem("poly1");
    monTexte=new QGraphicsTextItem("bonjour");
    monTexte->setPos(50,100);
    monTexte->setFlag(QGraphicsItem::ItemIsMovable);

    maScene->addItem(monTexte);
    maScene->addItem(poly1);
    maScene->addItem(ligne);

    ui->maVue->fitInView(maScene->sceneRect(), Qt::KeepAspectRatio );
    ui->maVue->setScene(maScene);
    ui->maVue->show();

}
