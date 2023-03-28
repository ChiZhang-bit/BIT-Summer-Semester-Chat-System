/********************************************************************************
** Form generated from reading UI file 'verifyform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYFORM_H
#define UI_VERIFYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyForm
{
public:

    void setupUi(QWidget *VerifyForm)
    {
        if (VerifyForm->objectName().isEmpty())
            VerifyForm->setObjectName(QStringLiteral("VerifyForm"));
        VerifyForm->resize(160, 50);

        retranslateUi(VerifyForm);

        QMetaObject::connectSlotsByName(VerifyForm);
    } // setupUi

    void retranslateUi(QWidget *VerifyForm)
    {
        VerifyForm->setWindowTitle(QApplication::translate("VerifyForm", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VerifyForm: public Ui_VerifyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYFORM_H
