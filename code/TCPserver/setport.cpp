#include "setport.h"
#include "ui_setport.h"
#include "tcpserver.h"

setport::setport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setport)
{
    ui->setupUi(this);
    ui->lineEdit->setText("5566");
}

setport::~setport()
{
    delete ui;
}

void setport::on_pushButton_clicked()
{
    tcpserver* tcp = tcpserver::gethand();
    tcp->getPort(ui->lineEdit->text());
    close();
}
