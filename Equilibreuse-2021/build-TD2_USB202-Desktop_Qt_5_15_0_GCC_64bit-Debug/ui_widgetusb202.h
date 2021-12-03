/********************************************************************************
** Form generated from reading UI file 'widgetusb202.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETUSB202_H
#define UI_WIDGETUSB202_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetUSB202
{
public:
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;

    void setupUi(QWidget *WidgetUSB202)
    {
        if (WidgetUSB202->objectName().isEmpty())
            WidgetUSB202->setObjectName(QString::fromUtf8("WidgetUSB202"));
        WidgetUSB202->resize(800, 600);
        pushButton = new QPushButton(WidgetUSB202);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 140, 80, 24));
        checkBox = new QCheckBox(WidgetUSB202);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(220, 140, 83, 22));
        checkBox_2 = new QCheckBox(WidgetUSB202);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(220, 170, 83, 22));
        checkBox_3 = new QCheckBox(WidgetUSB202);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(220, 200, 83, 22));
        checkBox_4 = new QCheckBox(WidgetUSB202);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(220, 240, 83, 22));

        retranslateUi(WidgetUSB202);

        QMetaObject::connectSlotsByName(WidgetUSB202);
    } // setupUi

    void retranslateUi(QWidget *WidgetUSB202)
    {
        WidgetUSB202->setWindowTitle(QCoreApplication::translate("WidgetUSB202", "WidgetUSB202", nullptr));
        pushButton->setText(QCoreApplication::translate("WidgetUSB202", "Quitter", nullptr));
        checkBox->setText(QCoreApplication::translate("WidgetUSB202", "LED1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("WidgetUSB202", "LED2", nullptr));
        checkBox_3->setText(QCoreApplication::translate("WidgetUSB202", "LED3", nullptr));
        checkBox_4->setText(QCoreApplication::translate("WidgetUSB202", "LED4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetUSB202: public Ui_WidgetUSB202 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETUSB202_H
