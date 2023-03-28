/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userlineEdit;
    QLabel *label_4;
    QPushButton *LoginButton;
    QLabel *label_5;
    QGraphicsView *graphicsView;
    QLineEdit *verlineEdit;
    QLabel *pwdlabel;
    QLineEdit *pwdlineEdit;
    QPushButton *RegButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 400);
        MainWindow->setMinimumSize(QSize(550, 400));
        MainWindow->setMaximumSize(QSize(550, 400));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 550, 400));
        label->setMinimumSize(QSize(550, 400));
        label->setMaximumSize(QSize(550, 400));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 80, 101, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\345\205\211\351\232\266\344\271\246_CNKI"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        userlineEdit = new QLineEdit(centralwidget);
        userlineEdit->setObjectName(QStringLiteral("userlineEdit"));
        userlineEdit->setGeometry(QRect(230, 80, 200, 30));
        QFont font1;
        font1.setPointSize(12);
        userlineEdit->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 310, 241, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\345\205\211\346\267\241\345\217\244\345\215\260_CNKI"));
        font2.setPointSize(13);
        label_4->setFont(font2);
        LoginButton = new QPushButton(centralwidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(200, 260, 90, 30));
        LoginButton->setFont(font1);
        LoginButton->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 160, 111, 30));
        label_5->setFont(font);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(230, 200, 160, 50));
        verlineEdit = new QLineEdit(centralwidget);
        verlineEdit->setObjectName(QStringLiteral("verlineEdit"));
        verlineEdit->setGeometry(QRect(230, 160, 200, 30));
        QFont font3;
        font3.setPointSize(11);
        verlineEdit->setFont(font3);
        pwdlabel = new QLabel(centralwidget);
        pwdlabel->setObjectName(QStringLiteral("pwdlabel"));
        pwdlabel->setGeometry(QRect(127, 120, 71, 30));
        pwdlabel->setFont(font);
        pwdlineEdit = new QLineEdit(centralwidget);
        pwdlineEdit->setObjectName(QStringLiteral("pwdlineEdit"));
        pwdlineEdit->setGeometry(QRect(230, 120, 200, 30));
        pwdlineEdit->setFont(font1);
        RegButton = new QPushButton(centralwidget);
        RegButton->setObjectName(QStringLiteral("RegButton"));
        RegButton->setGeometry(QRect(340, 260, 90, 30));
        RegButton->setFont(font1);
        RegButton->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        label_2->raise();
        userlineEdit->raise();
        label_4->raise();
        label_5->raise();
        LoginButton->raise();
        graphicsView->raise();
        verlineEdit->raise();
        pwdlabel->raise();
        pwdlineEdit->raise();
        RegButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        userlineEdit->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\344\270\212\347\275\221\344\270\215\346\266\211\345\257\206 \346\266\211\345\257\206\344\270\215\344\270\212\347\275\221", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\351\252\214\350\257\201\347\240\201", Q_NULLPTR));
        verlineEdit->setText(QString());
        pwdlabel->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        pwdlineEdit->setText(QString());
        RegButton->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
