/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QLineEdit *sendLineEdit;
    QPushButton *sendBtn;
    QLabel *userNameLabel;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *enterBtn;
    QLabel *IPLabel;
    QTextEdit *textEditClient;
    QListView *listViewOnline;
    QLabel *label;
    QTextEdit *textEditObject;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_background;
    QPushButton *pushButtonFont;
    QPushButton *pushButtonColor;
    QLineEdit *lineEditColorShow;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName(QStringLiteral("TcpClient"));
        TcpClient->resize(1072, 709);
        TcpClient->setStyleSheet(QStringLiteral(""));
        sendLineEdit = new QLineEdit(TcpClient);
        sendLineEdit->setObjectName(QStringLiteral("sendLineEdit"));
        sendLineEdit->setGeometry(QRect(50, 570, 691, 41));
        sendBtn = new QPushButton(TcpClient);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(650, 620, 91, 61));
        sendBtn->setCursor(QCursor(Qt::OpenHandCursor));
        sendBtn->setStyleSheet(QStringLiteral("border-image: url(:/back/qss/psblack/paperplane.png);"));
        userNameLabel = new QLabel(TcpClient);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(750, 50, 281, 31));
        QFont font;
        font.setPointSize(14);
        userNameLabel->setFont(font);
        userNameLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        userNameLabel->setFrameShape(QFrame::NoFrame);
        userNameLabel->setFrameShadow(QFrame::Plain);
        userNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        serverIPLabel = new QLabel(TcpClient);
        serverIPLabel->setObjectName(QStringLiteral("serverIPLabel"));
        serverIPLabel->setGeometry(QRect(750, 130, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(9);
        serverIPLabel->setFont(font1);
        serverIPLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        serverIPLineEdit = new QLineEdit(TcpClient);
        serverIPLineEdit->setObjectName(QStringLiteral("serverIPLineEdit"));
        serverIPLineEdit->setGeometry(QRect(850, 130, 181, 31));
        portLabel = new QLabel(TcpClient);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        portLabel->setGeometry(QRect(750, 170, 91, 31));
        QFont font2;
        font2.setPointSize(13);
        portLabel->setFont(font2);
        portLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        portLabel->setAlignment(Qt::AlignCenter);
        portLineEdit = new QLineEdit(TcpClient);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(850, 170, 181, 31));
        enterBtn = new QPushButton(TcpClient);
        enterBtn->setObjectName(QStringLiteral("enterBtn"));
        enterBtn->setGeometry(QRect(780, 210, 221, 71));
        QFont font3;
        font3.setPointSize(11);
        enterBtn->setFont(font3);
        enterBtn->setCursor(QCursor(Qt::OpenHandCursor));
        enterBtn->setLayoutDirection(Qt::LeftToRight);
        enterBtn->setStyleSheet(QStringLiteral("border-image: url(:/back/qss/psblack/icon_4.png);"));
        IPLabel = new QLabel(TcpClient);
        IPLabel->setObjectName(QStringLiteral("IPLabel"));
        IPLabel->setGeometry(QRect(750, 90, 281, 31));
        IPLabel->setFont(font);
        IPLabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        IPLabel->setFrameShape(QFrame::NoFrame);
        IPLabel->setFrameShadow(QFrame::Plain);
        IPLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        textEditClient = new QTextEdit(TcpClient);
        textEditClient->setObjectName(QStringLiteral("textEditClient"));
        textEditClient->setGeometry(QRect(50, 40, 691, 521));
        textEditClient->setReadOnly(true);
        listViewOnline = new QListView(TcpClient);
        listViewOnline->setObjectName(QStringLiteral("listViewOnline"));
        listViewOnline->setGeometry(QRect(750, 379, 281, 301));
        listViewOnline->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewOnline->setDragDropMode(QAbstractItemView::NoDragDrop);
        listViewOnline->setSelectionMode(QAbstractItemView::SingleSelection);
        listViewOnline->setSelectionBehavior(QAbstractItemView::SelectRows);
        label = new QLabel(TcpClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(760, 280, 81, 41));
        textEditObject = new QTextEdit(TcpClient);
        textEditObject->setObjectName(QStringLiteral("textEditObject"));
        textEditObject->setGeometry(QRect(850, 290, 181, 31));
        textEditObject->setReadOnly(true);
        label_2 = new QLabel(TcpClient);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(800, 320, 41, 51));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/back/qss/psblack/customer.png);"));
        label_3 = new QLabel(TcpClient);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(860, 330, 121, 41));
        QFont font4;
        font4.setPointSize(16);
        label_3->setFont(font4);
        label_3->setAlignment(Qt::AlignCenter);
        label_background = new QLabel(TcpClient);
        label_background->setObjectName(QStringLiteral("label_background"));
        label_background->setGeometry(QRect(0, 0, 1072, 709));
        pushButtonFont = new QPushButton(TcpClient);
        pushButtonFont->setObjectName(QStringLiteral("pushButtonFont"));
        pushButtonFont->setGeometry(QRect(50, 640, 71, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Agency FB"));
        font5.setPointSize(8);
        pushButtonFont->setFont(font5);
        pushButtonColor = new QPushButton(TcpClient);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));
        pushButtonColor->setGeometry(QRect(130, 640, 71, 41));
        pushButtonColor->setFont(font5);
        lineEditColorShow = new QLineEdit(TcpClient);
        lineEditColorShow->setObjectName(QStringLiteral("lineEditColorShow"));
        lineEditColorShow->setGeometry(QRect(210, 650, 21, 27));
        lineEditColorShow->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lineEditColorShow->setReadOnly(true);
        label_background->raise();
        sendLineEdit->raise();
        sendBtn->raise();
        userNameLabel->raise();
        serverIPLabel->raise();
        serverIPLineEdit->raise();
        portLabel->raise();
        portLineEdit->raise();
        enterBtn->raise();
        IPLabel->raise();
        textEditClient->raise();
        listViewOnline->raise();
        label->raise();
        textEditObject->raise();
        label_2->raise();
        label_3->raise();
        pushButtonFont->raise();
        pushButtonColor->raise();
        lineEditColorShow->raise();

        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QApplication::translate("TcpClient", "Form", Q_NULLPTR));
        sendBtn->setText(QString());
        userNameLabel->setText(QApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        serverIPLabel->setText(QApplication::translate("TcpClient", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", Q_NULLPTR));
        portLabel->setText(QApplication::translate("TcpClient", "\347\253\257\345\217\243", Q_NULLPTR));
        enterBtn->setText(QApplication::translate("TcpClient", "\350\277\233\345\205\245\350\201\212\345\244\251\345\256\244", Q_NULLPTR));
        IPLabel->setText(QApplication::translate("TcpClient", "IP", Q_NULLPTR));
        label->setText(QApplication::translate("TcpClient", "\345\275\223\345\211\215\351\200\211\344\270\255\357\274\232", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("TcpClient", "\345\234\250\347\272\277\346\210\220\345\221\230", Q_NULLPTR));
        label_background->setText(QString());
        pushButtonFont->setText(QApplication::translate("TcpClient", "\344\277\256\346\224\271\345\255\227\344\275\223", Q_NULLPTR));
        pushButtonColor->setText(QApplication::translate("TcpClient", "\344\277\256\346\224\271\351\242\234\350\211\262", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
