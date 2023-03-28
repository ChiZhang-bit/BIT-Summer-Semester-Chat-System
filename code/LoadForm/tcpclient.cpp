#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QHostInfo>
#include <QStringListModel>


TcpClient::~TcpClient()
{
    delete ui;
}

TcpClient::TcpClient(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    setWindowTitle(tr("TCP Client"));
    //QPixmap map("./background2.jpg");
    ui->label_background->setStyleSheet("background-image:url(./background2.png); background-position:top left;background-repeat:repeat-xy;");
    ui->textEditClient->setStyleSheet("background-color:rgba(255,255,255,0.7)");
    ui->sendLineEdit->setStyleSheet("background-color:rgba(255,255,255,0.7)");
    ui->listViewOnline->setStyleSheet("background-color:rgba(255,255,255,0.7)");
    QString localHostName = QHostInfo::localHostName();
    qDebug() << "localHostName : " << localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address, info.addresses()) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol
                && address.toString().left(3) != "192") {
            qDebug() << "IP : " << address.toString();
            ip = address.toString();
        }
    }
    ui->IPLabel->setText("IP:" + ip);
    status = false;
    port = 5566;
    ui->portLineEdit->setText(QString::number(port));
    //ui->serverIPLineEdit->setText(QString::fromStdString("10.194.144.46"));

    serverIP =new QHostAddress();
    ui->sendBtn->setEnabled(status);
    currentObject = "[群聊]";
    ui->textEditObject->setText("[群聊]");
}



void TcpClient::SetId(QString s_id) {
    id = s_id;
}

void TcpClient::SetIdText(QString id) {
    ui->userNameLabel->setText("ID:" + id);
}

void TcpClient::on_enterBtn_clicked()
{
    if(!status)
    {
        QString ip = ui->serverIPLineEdit->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this, "错误", "IP地址错误");
            return;
        }

        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(*serverIP,port);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slot_Connected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(slot_dataReceived()));

        status=true;
    }
    else
    {
        QString msg= ":L[" + id + "]:" + "Leave Chat Room";
        tcpSocket->write(msg.toUtf8().data());
        tcpSocket->disconnectFromHost();
        status=false;
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slot_Disconnected()));
    }
}

void TcpClient::slot_Connected()
{
    ui->sendBtn->setEnabled(true);
    ui->enterBtn->setText("离开聊天室");
    QString msg = ":E[" + id + "]:" + "Enter Chat Room";

    tcpSocket->write(msg.toUtf8().data());
}

void TcpClient::on_sendBtn_clicked()
{
    if(ui->sendLineEdit->text() == "")
            {
                QMessageBox::warning(this, "错误", "消息不能为空");
                return;
            }
    if(ui->sendLineEdit->text().contains('[') || ui->sendLineEdit->text().contains(']') || ui->sendLineEdit->text().contains(':') || ui->sendLineEdit->text().contains('$'))
            {
                QMessageBox::warning(this, "错误", "消息中不能含有'['']'':''$'");
                return;
            }

    if(currentObject != "[群聊]")
    {
        if(ui->sendLineEdit->text() == "") {
            return;
        }
        QString msg = ":S[" + id + "]" + "[" + currentObject + "]:\n    " + ui->sendLineEdit->text();
        tcpSocket->write(msg.toUtf8().data());
        ui->sendLineEdit->clear();
        return;
    }

    if(ui->sendLineEdit->text()=="")
    {
        return ;
    }
    QString msg = ":M[" + id + "]:\n    " + ui->sendLineEdit->text();
    tcpSocket->write(msg.toUtf8().data());
    ui->sendLineEdit->clear();
}

void TcpClient::slot_Disconnected()
{
    ui->sendBtn->setEnabled(false);
    ui->enterBtn->setText("进入聊天室");
    ui->textEditClient->clear();
    currentObject = "[群聊]";
    ui->textEditObject->setText("[群聊]");
    res.clear();
    QStringListModel *Model = new QStringListModel(res);
    ui->listViewOnline->setModel(Model);
}

void TcpClient::slot_dataReceived()
{
    QByteArray array = tcpSocket->readAll();
    QString msg = array;

    //qDebug()<<"now client get msg:"<<msg;

    if(msg[0] == ':')
    {
        int i=3;
        QString clientA = "";
        while(msg[i] != ']')
        {
            clientA += msg[i++];
        }

        if(clientA == id && msg[1] == 'S')
        {
            QString clientB = "";
            i += 2;
            while(msg[i] != ']')
            {
                clientB += msg[i++];
            }

            QString true_msg = "";
            i++;
            while(i < msg.length())
            {
                true_msg += msg[i++];
            }
            true_msg = "你私聊" + clientB + "说" + true_msg;

            QTime current_time = QTime::currentTime();
            int hour = current_time.hour();
            int minute = current_time.minute();
            int second = current_time.second();
            true_msg = "[" + QString::number(hour,10) + ":" + QString::number(minute,10) + ":" + QString::number(second,10) + "]" + true_msg;

            ui->textEditClient->append(true_msg);
            return;
        }
        else if(msg[1] == 'S')
        {
            return;
        }

        QString true_msg = clientA;
        i++;
        while(i < msg.length())
        {
            true_msg += msg[i++];
        }

        QTime current_time = QTime::currentTime();
        int hour = current_time.hour();
        int minute = current_time.minute();
        int second = current_time.second();
        true_msg = "[" + QString::number(hour,10) + ":" + QString::number(minute,10) + ":" + QString::number(second,10) + "]" + true_msg;

        ui->textEditClient->append(true_msg);
    }

    else if(msg[0] == '*')
    {
        int i=1;
        res.clear();
        res.append("[群聊]");
        QString currentListandautoinfo = "";
        while(i < msg.length())
        {
            currentListandautoinfo += msg[i++];
        }

        //转currentList为QStringList//
        QString uname = "";
        for(i=0; i<currentListandautoinfo.length(); i++)
        {
            if(currentListandautoinfo[i] == ':')
            {
                break;
            }
            else if(currentListandautoinfo[i] == '[')
            {
                res.append(uname);
                uname = "";
            }
            else
            {
                uname += currentListandautoinfo[i];
            }
        }
        if(uname != "") {
            res.append(uname);
            QStringListModel *Model = new QStringListModel(res);
            ui->listViewOnline->setModel(Model);
        }

        i += 3;
        QString clientA = "";
        while(currentListandautoinfo[i] != ']')
        {
            clientA += currentListandautoinfo[i++];
        }

        QString true_msg = clientA;
        i++;
        while(i < currentListandautoinfo.length())
        {
            true_msg += currentListandautoinfo[i++];
        }

        QTime current_time = QTime::currentTime();
        int hour = current_time.hour();
        int minute = current_time.minute();
        int second = current_time.second();
        true_msg = "[" + QString::number(hour,10) + ":" + QString::number(minute,10) + ":" + QString::number(second,10) + "]" + true_msg;

        ui->textEditClient->append(true_msg);
    }

    else if(msg[0] == '$')
    {
        int i=1;
        QString clientA = "";
        while(msg[i] != ':')
        {
            clientA += msg[i++];
        }

        QString true_msg = "";
        while(msg[i] != '$')
        {
            true_msg += msg[i++];
        }

        true_msg = clientA + "私聊你说" + true_msg;

        QTime current_time = QTime::currentTime();
        int hour = current_time.hour();
        int minute = current_time.minute();
        int second = current_time.second();
        true_msg = "[" + QString::number(hour,10) + ":" + QString::number(minute,10) + ":" + QString::number(second,10) + "]" + true_msg;

        ui->textEditClient->append(true_msg);
    }
}


void TcpClient::on_listViewOnline_doubleClicked(const QModelIndex &index)
{
    QString strtemp;
    strtemp = index.data().toString();
    if(!strtemp.isEmpty()) {
        currentObject = strtemp;
        ui->textEditObject->setText(strtemp);
    }

}

void TcpClient::on_pushButtonFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("consolas",9), this, "设置聊天字体");
    if(ok)
    {
        ui->textEditClient->setFont(font);
    }
}

void TcpClient::on_pushButtonColor_clicked()
{
    QColor c = QColorDialog::getColor();
    if(c.isValid()){
        int r = c.red();
        int g = c.green();
        int b = c.blue();
        QString style_show = QString("background-color:rgb(%1,%2,%3)").arg(r).arg(g).arg(b);
        ui->lineEditColorShow->setStyleSheet(style_show);
        QString style_text = QString("color:rgb(%1,%2,%3);background-color:rgba(255,255,255,0.7)").arg(r).arg(g).arg(b);
        ui->textEditClient->setStyleSheet(style_text);
    }
}
