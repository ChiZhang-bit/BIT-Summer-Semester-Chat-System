/********************************************************************************
** Form generated from reading UI file 'regsucceeform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGSUCCEEFORM_H
#define UI_REGSUCCEEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegSucceeForm
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *RegSucceeForm)
    {
        if (RegSucceeForm->objectName().isEmpty())
            RegSucceeForm->setObjectName(QStringLiteral("RegSucceeForm"));
        RegSucceeForm->resize(363, 255);
        label = new QLabel(RegSucceeForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 151, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(18);
        label->setFont(font);
        pushButton = new QPushButton(RegSucceeForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 150, 121, 41));

        retranslateUi(RegSucceeForm);

        QMetaObject::connectSlotsByName(RegSucceeForm);
    } // setupUi

    void retranslateUi(QWidget *RegSucceeForm)
    {
        RegSucceeForm->setWindowTitle(QApplication::translate("RegSucceeForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("RegSucceeForm", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("RegSucceeForm", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegSucceeForm: public Ui_RegSucceeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGSUCCEEFORM_H
