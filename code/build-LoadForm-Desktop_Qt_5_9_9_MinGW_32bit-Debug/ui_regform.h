/********************************************************************************
** Form generated from reading UI file 'regform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGFORM_H
#define UI_REGFORM_H

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

class Ui_RegForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userlineEdit;
    QLabel *label_3;
    QLineEdit *pwdlineEdit;
    QPushButton *ConButton;
    QPushButton *CancalButton;
    QLabel *label_4;
    QLabel *RegMessage;
    QLabel *label_5;
    QLineEdit *pwdlineEdit_2;

    void setupUi(QWidget *RegForm)
    {
        if (RegForm->objectName().isEmpty())
            RegForm->setObjectName(QStringLiteral("RegForm"));
        RegForm->resize(409, 438);
        label = new QLabel(RegForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 10, 121, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\345\205\211\351\255\217\344\275\223_CNKI"));
        font.setPointSize(29);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(RegForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 110, 71, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        userlineEdit = new QLineEdit(RegForm);
        userlineEdit->setObjectName(QStringLiteral("userlineEdit"));
        userlineEdit->setGeometry(QRect(160, 115, 141, 31));
        label_3 = new QLabel(RegForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 160, 71, 41));
        label_3->setFont(font1);
        pwdlineEdit = new QLineEdit(RegForm);
        pwdlineEdit->setObjectName(QStringLiteral("pwdlineEdit"));
        pwdlineEdit->setGeometry(QRect(160, 165, 141, 31));
        ConButton = new QPushButton(RegForm);
        ConButton->setObjectName(QStringLiteral("ConButton"));
        ConButton->setGeometry(QRect(80, 300, 101, 41));
        CancalButton = new QPushButton(RegForm);
        CancalButton->setObjectName(QStringLiteral("CancalButton"));
        CancalButton->setGeometry(QRect(220, 300, 101, 41));
        label_4 = new QLabel(RegForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 80, 221, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\345\205\211\351\255\217\344\275\223_CNKI"));
        font2.setUnderline(false);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 82, 29);"));
        RegMessage = new QLabel(RegForm);
        RegMessage->setObjectName(QStringLiteral("RegMessage"));
        RegMessage->setGeometry(QRect(80, 260, 221, 31));
        RegMessage->setFont(font2);
        RegMessage->setStyleSheet(QStringLiteral("color: rgb(209, 71, 255);"));
        label_5 = new QLabel(RegForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 215, 91, 41));
        label_5->setFont(font1);
        pwdlineEdit_2 = new QLineEdit(RegForm);
        pwdlineEdit_2->setObjectName(QStringLiteral("pwdlineEdit_2"));
        pwdlineEdit_2->setGeometry(QRect(160, 220, 141, 31));

        retranslateUi(RegForm);

        QMetaObject::connectSlotsByName(RegForm);
    } // setupUi

    void retranslateUi(QWidget *RegForm)
    {
        RegForm->setWindowTitle(QApplication::translate("RegForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("RegForm", "\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegForm", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegForm", "\345\257\206\347\240\201", Q_NULLPTR));
        ConButton->setText(QApplication::translate("RegForm", "\346\263\250\345\206\214", Q_NULLPTR));
        CancalButton->setText(QApplication::translate("RegForm", "\345\217\226\346\266\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegForm", "*\350\257\267\350\256\276\347\275\256\346\202\250\347\232\204\347\224\250\346\210\267\345\220\215\345\222\214\345\257\206\347\240\201", Q_NULLPTR));
        RegMessage->setText(QString());
        label_5->setText(QApplication::translate("RegForm", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegForm: public Ui_RegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGFORM_H
