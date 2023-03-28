#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QDebug>
#include "tcpclient.h"
#include "verifyform.h"
#include "regform.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();
    void slot_connected();
    void slot_datareceived();
    void slot_disconnected();
    void on_RegButton_clicked();

private:
    int temp;
    Ui::MainWindow *ui;
    VerifyForm *verifyform;
    TcpClient *tcpclient;
    RegForm *regform;
    QString code;
    QTcpSocket *tcpsocket;
    QHostAddress *serverip;
    int flag = 2;
    QString id;
    QString password;

};
#endif
// MAINWINDOW_H
