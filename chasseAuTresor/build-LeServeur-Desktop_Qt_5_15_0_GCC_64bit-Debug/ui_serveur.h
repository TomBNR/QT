/********************************************************************************
** Form generated from reading UI file 'serveur.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVEUR_H
#define UI_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serveur
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButtonLancerServeur;
    QPushButton *pushButtonQuitterServeur;

    void setupUi(QWidget *Serveur)
    {
        if (Serveur->objectName().isEmpty())
            Serveur->setObjectName(QString::fromUtf8("Serveur"));
        Serveur->resize(800, 600);
        widget = new QWidget(Serveur);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 550, 571, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        pushButtonLancerServeur = new QPushButton(widget);
        pushButtonLancerServeur->setObjectName(QString::fromUtf8("pushButtonLancerServeur"));

        horizontalLayout->addWidget(pushButtonLancerServeur);

        pushButtonQuitterServeur = new QPushButton(widget);
        pushButtonQuitterServeur->setObjectName(QString::fromUtf8("pushButtonQuitterServeur"));

        horizontalLayout->addWidget(pushButtonQuitterServeur);


        retranslateUi(Serveur);
        QObject::connect(pushButtonQuitterServeur, SIGNAL(clicked()), Serveur, SLOT(close()));

        QMetaObject::connectSlotsByName(Serveur);
    } // setupUi

    void retranslateUi(QWidget *Serveur)
    {
        Serveur->setWindowTitle(QCoreApplication::translate("Serveur", "Serveur", nullptr));
        label->setText(QCoreApplication::translate("Serveur", "Port d'\303\251coute", nullptr));
        spinBox->setSpecialValueText(QCoreApplication::translate("Serveur", "8888", nullptr));
        pushButtonLancerServeur->setText(QCoreApplication::translate("Serveur", "Lancement", nullptr));
        pushButtonQuitterServeur->setText(QCoreApplication::translate("Serveur", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serveur: public Ui_Serveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVEUR_H
