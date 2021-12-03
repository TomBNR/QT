#include "threadavecwidget.h"
#include "ui_threadavecwidget.h"
#include "monthread.h"

ThreadAvecWidget::ThreadAvecWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThreadAvecWidget)
{
    ui->setupUi(this);
}

ThreadAvecWidget::~ThreadAvecWidget()
{
    delete ui;
}


void ThreadAvecWidget::on_pushButtonLancer_clicked()
{
    MonThread *tab[5];
     for (int i=0;i<5;i++){
         tab[i]=new MonThread(QString::number(i));
         QObject::connect(tab[i],&MonThread::monId,this,&ThreadAvecWidget::on_MonThreadMonId);
     }
     tab[0]->start();
     tab[1]->start();
     tab[2]->start();
     tab[3]->start();
     tab[4]->start();


}

void ThreadAvecWidget::on_MonThreadMonId(quint64 id)
{

}
