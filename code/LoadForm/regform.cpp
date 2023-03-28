#include "regform.h"
#include "ui_regform.h"

RegForm::RegForm(/*QTcpSocket *tcpSocket,*/ QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegForm)
{
    ui->setupUi(this);
    //tcpsocket = tcpSocket;
    ui->pwdlineEdit->setEchoMode(QLineEdit::Password);
    ui->pwdlineEdit_2->setEchoMode(QLineEdit::Password);
}

RegForm::~RegForm()
{
    delete ui;
}

void RegForm::on_ConButton_clicked()
{
    if(ui->userlineEdit->text() == "") {
        ui->RegMessage->setText("注册失败，用户名不能为空！");
    }
    else if(ui->userlineEdit->text().contains('[')
            || ui->userlineEdit->text().contains(']')
            || ui->userlineEdit->text().contains(':') ) {
        ui->RegMessage->setText("注册失败，用户名非法！");
    }
    else if(ui->pwdlineEdit->text() != ui->pwdlineEdit_2->text()) {
        ui->RegMessage->setText("注册失败，密码不一致！");
    }
    else if(ui->pwdlineEdit->text() == "") {
        ui->RegMessage->setText("注册失败，密码不能为空！");
    }
    else {
        //regsucceeform = new RegSucceeForm();
        //regsucceeform->show();
        ui->RegMessage->clear();
        tcpsocket = new QTcpSocket(this);
        serverip = new QHostAddress();
        serverip ->setAddress("10.194.157.97");
        tcpsocket->connectToHost(*serverip, 5566);
        connect(tcpsocket, SIGNAL(connected()), this, SLOT(slot_connected()));


        //connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(slot_datareceived()));
        this->close();
    }
}

void RegForm::on_CancalButton_clicked()
{
    this->close();
}

void RegForm::slot_connected() {
    qDebug() << "=====Before Reg : Connected.";
    QString msg = "%" + ui->userlineEdit->text() + "%" + ui->pwdlineEdit->text() + "%";
    tcpsocket->write(msg.toUtf8().data());
    qDebug() << "=====msg : " << msg;
    tcpsocket->disconnectFromHost();
}

//void RegForm::slot_datereceived(){
//}
