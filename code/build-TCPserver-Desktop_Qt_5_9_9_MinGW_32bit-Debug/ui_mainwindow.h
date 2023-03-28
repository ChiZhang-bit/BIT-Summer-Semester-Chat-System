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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_off;
    QLabel *label;
    QPushButton *pushButton_on;
    QComboBox *comboBox;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(230, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_off = new QPushButton(centralwidget);
        pushButton_off->setObjectName(QStringLiteral("pushButton_off"));
        pushButton_off->setGeometry(QRect(10, 50, 211, 30));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        pushButton_off->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 211, 101));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background-color: rgb(7, 189, 255);"));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        pushButton_on = new QPushButton(centralwidget);
        pushButton_on->setObjectName(QStringLiteral("pushButton_on"));
        pushButton_on->setGeometry(QRect(10, 10, 211, 30));
        pushButton_on->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 210, 171, 31));
        comboBox->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 260, 191, 91));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 230, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_off->setText(QApplication::translate("MainWindow", "\344\270\255\346\255\242\346\234\215\345\212\241", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ZZZ\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        pushButton_on->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\346\234\215\345\212\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
