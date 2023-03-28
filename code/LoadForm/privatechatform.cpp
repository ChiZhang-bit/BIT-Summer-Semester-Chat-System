#include "privatechatform.h"
#include "ui_privatechatform.h"

PrivateChatForm::PrivateChatForm(QTcpSocket *tcpsocket, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrivateChatForm)
{
    ui->setupUi(this);
    tcpSocket = tcpsocket;
}

PrivateChatForm::~PrivateChatForm()
{
    delete ui;
}

void PrivateChatForm::setid(QString s_id, QString to_s_id) {
    id = s_id;
    to_id = to_s_id;
}

void PrivateChatForm::on_sendButton_clicked()
{
    if(ui->sendlineEdit->text() == "") {
        return;
    }
    QString msg = ":S[" + id + "]" + "[" + to_id + "]:" + ui->sendlineEdit->text();
    tcpSocket->write(msg.toUtf8().data());
    ui->sendlineEdit->clear();
}
