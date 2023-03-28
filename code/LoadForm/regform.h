#ifndef REGFORM_H
#define REGFORM_H

#include <QWidget>
#include <regsucceeform.h>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class RegForm;
}

class RegForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegForm(/*QTcpSocket *tcpSocket,*/ QWidget *parent = nullptr);
    ~RegForm();

private slots:
    void on_ConButton_clicked();
    void on_CancalButton_clicked();
    void slot_connected();
    //void slot_datereceived();

private:
    Ui::RegForm *ui;
    RegSucceeForm *regsucceeform;
    QTcpSocket *tcpsocket;
    QHostAddress *serverip;

};

#endif // REGFORM_H
