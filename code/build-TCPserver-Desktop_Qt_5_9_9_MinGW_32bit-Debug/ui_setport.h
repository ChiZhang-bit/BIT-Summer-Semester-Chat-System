/********************************************************************************
** Form generated from reading UI file 'setport.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPORT_H
#define UI_SETPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setport
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *setport)
    {
        if (setport->objectName().isEmpty())
            setport->setObjectName(QStringLiteral("setport"));
        setport->resize(200, 120);
        label = new QLabel(setport);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 161, 20));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        lineEdit = new QLineEdit(setport);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 121, 27));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(setport);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 80, 101, 29));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        pushButton->setFont(font1);

        retranslateUi(setport);

        QMetaObject::connectSlotsByName(setport);
    } // setupUi

    void retranslateUi(QWidget *setport)
    {
        setport->setWindowTitle(QApplication::translate("setport", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("setport", " \350\257\267\350\256\276\347\275\256\346\234\254\346\234\215\345\212\241\345\231\250 port", Q_NULLPTR));
        pushButton->setText(QApplication::translate("setport", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class setport: public Ui_setport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPORT_H
