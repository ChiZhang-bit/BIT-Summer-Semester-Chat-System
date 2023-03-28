#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int temp = 0;
    ui->setupUi(this);
    /*UI.SET*/
    QDir dir;
    QPixmap map("./background1.png");
    ui->label->setPixmap(map);
    //ui->label->setWindowOpacity(0.1);
    ui->userlineEdit->setStyleSheet("background-color:rgba(0,0,0,0.3)");
    ui->pwdlineEdit->setStyleSheet("background-color:rgba(0,0,0,0.3)");
    ui->pwdlineEdit->setEchoMode(QLineEdit::Password);
    ui->verlineEdit->setStyleSheet("background-color:rgba(0,0,0,0.3)");
    qDebug() << "Set background OK";

    verifyform = new VerifyForm();
    verifyform->setParent(this);
    verifyform->show();
    QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
    verifyform->move(globalPos.x()+230, globalPos.y()+200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
    if(ui->userlineEdit->text() == "")
            {
                QMessageBox::warning(this, "错误", "用户名不能为空");
                return;
            }
    if(ui->userlineEdit->text().contains('[') || ui->userlineEdit->text().contains(']') || ui->userlineEdit->text().contains(':') || ui->userlineEdit->text().contains('$'))
            {
                QMessageBox::warning(this, "错误", "用户名不能含有'['']'':''$'");
                return;
            }
    code = verifyform->getcode();
    if(/*ui->pwdlineEdit->text() == "123456" && */ui->verlineEdit->text() == code){
        tcpsocket = new QTcpSocket(this);
        serverip = new QHostAddress();
        serverip ->setAddress("10.194.157.97");
        tcpsocket->connectToHost(*serverip, 5566);
        qDebug() << "=====serverip : " << serverip->toString();
        connect(tcpsocket, SIGNAL(connected()), this, SLOT(slot_connected()));
        connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(slot_datareceived()));
        //qDebug() << "****====temp : " << temp;
//        if(temp){

//        }
    }
}

void MainWindow::slot_connected() {
    qDebug() << "=====Before Login : Connected.";
    QString msg = "#" + ui->userlineEdit->text() + "#" + ui->pwdlineEdit->text() + "#";
    tcpsocket->write(msg.toUtf8().data());
    qDebug() << "=====msg : " << msg;
}

void MainWindow::slot_disconnected() {
    qDebug() << "=====disconnected";
}

void MainWindow::slot_datareceived() {
    QByteArray array = tcpsocket->readAll();
    QString msg = array;
    qDebug() << "=====msg : " << msg;
    if(msg == "&20&") {
        //temp = 1;
        id = ui->userlineEdit->text();
        //password = ui->pwdlineEdit->text();
        tcpclient = new TcpClient();
        tcpclient->SetId(this->id);
        tcpclient->SetIdText(this->id);
        tcpclient->show();
        tcpsocket->disconnectFromHost();
        connect(tcpsocket,SIGNAL(disconnected()),this,SLOT(slot_disconnected()));
        this->close();
        qDebug() << "登陆成功";
    }
    qDebug() << "*****====temp : " <<temp;
}

void MainWindow::on_RegButton_clicked()
{
    regform = new RegForm(/*tcpsocket*/);
    regform->show();
}
