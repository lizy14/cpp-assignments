/********************************************************************************
** Form generated from reading UI file 'tempconverter.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPCONVERTER_H
#define UI_TEMPCONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tempConverterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupC;
    QVBoxLayout *verticalLayout;
    QLCDNumber *lcdC;
    QDial *dialC;
    QGroupBox *groupF;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *lcdF;
    QDial *dialF;
    QLabel *label;

    void setupUi(QMainWindow *tempConverterClass)
    {
        if (tempConverterClass->objectName().isEmpty())
            tempConverterClass->setObjectName(QStringLiteral("tempConverterClass"));
        tempConverterClass->resize(674, 505);
        tempConverterClass->setContextMenuPolicy(Qt::DefaultContextMenu);
        centralWidget = new QWidget(tempConverterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupC = new QGroupBox(centralWidget);
        groupC->setObjectName(QStringLiteral("groupC"));
        verticalLayout = new QVBoxLayout(groupC);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lcdC = new QLCDNumber(groupC);
        lcdC->setObjectName(QStringLiteral("lcdC"));

        verticalLayout->addWidget(lcdC);

        dialC = new QDial(groupC);
        dialC->setObjectName(QStringLiteral("dialC"));
        dialC->setMinimum(-50);
        dialC->setMaximum(150);

        verticalLayout->addWidget(dialC);


        gridLayout->addWidget(groupC, 1, 0, 1, 1);

        groupF = new QGroupBox(centralWidget);
        groupF->setObjectName(QStringLiteral("groupF"));
        verticalLayout_2 = new QVBoxLayout(groupF);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lcdF = new QLCDNumber(groupF);
        lcdF->setObjectName(QStringLiteral("lcdF"));

        verticalLayout_2->addWidget(lcdF);

        dialF = new QDial(groupF);
        dialF->setObjectName(QStringLiteral("dialF"));
        dialF->setMinimum(-58);
        dialF->setMaximum(302);

        verticalLayout_2->addWidget(dialF);


        gridLayout->addWidget(groupF, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 2);

        tempConverterClass->setCentralWidget(centralWidget);

        retranslateUi(tempConverterClass);

        QMetaObject::connectSlotsByName(tempConverterClass);
    } // setupUi

    void retranslateUi(QMainWindow *tempConverterClass)
    {
        tempConverterClass->setWindowTitle(QApplication::translate("tempConverterClass", "\346\270\251\345\272\246\346\215\242\347\256\227\345\231\250 - By Zhaoyang - Uses Qt 5.3", 0));
        groupC->setTitle(QApplication::translate("tempConverterClass", "Celsius - \346\221\204\346\260\217\345\272\246", 0));
        groupF->setTitle(QApplication::translate("tempConverterClass", "Fahrenheit - \345\215\216\346\260\217\345\272\246", 0));
        label->setText(QApplication::translate("tempConverterClass", "Welcome to temperature converter!", 0));
    } // retranslateUi

};

namespace Ui {
    class tempConverterClass: public Ui_tempConverterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPCONVERTER_H
