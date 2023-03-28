#include "tcpclientsocket.h"

tcpclientsocket::tcpclientsocket(QObject *)
{
    connect(this,
            &tcpclientsocket::readyRead,
            this,
            &tcpclientsocket::receiveData);

    connect(this,
            &tcpclientsocket::disconnected,
            this,
            &tcpclientsocket::slot_clientDisconnected);
}

void tcpclientsocket::receiveData()
{
    QByteArray array = readAll();
    QString msg = array;
    //qDebug() << "====msg : " << msg;
    if(msg.at(0) == '#') {
        int i = 1;
        QString msg_username = "";
        while(msg[i] != '#') {
            msg_username += msg.at(i++);
        }
        i++;
        QString msg_pwd = "";
        while(msg[i] != '#') {
            msg_pwd += msg.at(i++);
        }
        qDebug() << "====msg_username : " << msg_username;
        qDebug() << "====msg_pwd : " << msg_pwd;
        emit sig_verusers(msg_username, msg_pwd);
        return;
    }
    else if(msg.at(0) == '%') {
        int i = 1;
        QString msg_username = "";
        while(msg[i] != '%') {
            msg_username += msg.at(i++);
        }
        i++;
        QString msg_pwd = "";
        while(msg[i] != '%') {
            msg_pwd += msg.at(i++);
        }
        qDebug() << "====msg_username : " << msg_username;
        qDebug() << "====msg_pwd : " << msg_pwd;
        emit sig_regusers(msg_username, msg_pwd);
        return;
    }
    emit sig_updateServer(msg);
}

void tcpclientsocket::slot_clientDisconnected()
{
    emit sig_clientDisconnected(this->socketDescriptor());
}
