#include "subserver.h"
#include <QHostAddress>

static int numid = 1000;

subserver::subserver(QObject *parent, QString port):QTcpServer(parent)
{
    listen(QHostAddress::Any, port.toInt());
}

void subserver::incomingConnection(int socketDescriptor)
{
    MySql* sqlconnect = MySql::gethand();

    QString condition = "username is NULL";
    sqlconnect->DeleteData("Online_user",condition);

    //每次新来一个客户端 加入服务器 Online_user
    //对应： sub_id - auto (hereeeeeeeee)
    //username - sub_id - auto(hereeeeeeeee)
    //------------------------------------------------------

    sqlconnect->openDatabase();
    sqlconnect->newConnectuser(++numid, socketDescriptor);
    //--------------------------------------------------------

    tcpclientsocket *clientsocket = new tcpclientsocket(this);

    connect(clientsocket,
            &tcpclientsocket::sig_updateServer,
            this,
            &subserver::slot_updateServer);

    connect(clientsocket,
            &tcpclientsocket::sig_clientDisconnected,
            this,
            &subserver::slot_clientDisconnect);

    connect(clientsocket,
            &tcpclientsocket::sig_verusers,
            this,
            &subserver::slot_verifyusers);

    connect(clientsocket,
            &tcpclientsocket::sig_regusers,
            this,
            &subserver::slot_regusers);

    clientsocket->setSocketDescriptor(socketDescriptor);

    tcpclientsocketlist.append(clientsocket);
}

void subserver::slot_verifyusers(QString msg_username, QString msg_pwd) {
    //--------------------------------------
    //true or false password<---->username

    MySql* sqlconnect = MySql::gethand();
    bool success = sqlconnect->verify_user("Users",msg_username,msg_pwd);

    QString message;
    if(success == true){
        message = "&20&";
    }

    else{
        message = "&10&";
    }
    qDebug()<<"message = " << message;

    for(int i=0; i<tcpclientsocketlist.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        item->write(message.toUtf8().data());
    }
    //---------------------------------


}

void subserver::slot_regusers(QString username , QString password){
    //-------------------------------------------
    // insert add into sql

    MySql* sqlconnect = MySql::gethand();
    sqlconnect->Register_user("Users",username,password);

    //-------------------------------------------
}

void subserver::slot_updateServer(QString msg)
{
    emit sig_updateServer(msg);

    for(int i=0; i<tcpclientsocketlist.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        if(msg != "") {
            item->write(msg.toUtf8().data());
        }
    }
}


void subserver::slot_clientDisconnect(int descriptor)
{


    for(int i=0; i<tcpclientsocketlist.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        if(item->socketDescriptor() == descriptor)
        {
            tcpclientsocketlist.removeAt(i);
            return;
        }
    }

    MySql* sqlconnect = MySql::gethand();
    QString condition = "username is NULL";
    sqlconnect->DeleteData("Online_user",condition);

    return;
}

void subserver::deliverMessage(QString msg, int descriptor)
{
    if(descriptor == -2)
        {
            for(int i=0; i<tcpclientsocketlist.count(); i++)
            {
                QTcpSocket *item = tcpclientsocketlist.at(i);
                item->write(msg.toUtf8().data());
            }
            return;
        }

    for(int i=0; i<tcpclientsocketlist.count(); i++)
    {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        if(item->socketDescriptor() == descriptor)
        {
            item->write(msg.toUtf8().data());
            return;
        }
    }
    return;
}

void subserver::deleteItem(int descriptor)
{
    qDebug()<<"now descr:  "<<descriptor;

    //delete--------------------------
    MySql* sqlconnected = MySql::gethand();
    QString condition = "autoid = ";
    condition += QString::number(descriptor);
    sqlconnected->DeleteData("Online_user", condition);

    QString currentList = sqlconnected->Get_All_Online_usersname("Online_user");
    QString list_msg = "*" + currentList;

    deliverMessage(list_msg, -2);
    return;
}

int subserver::getNumid()
{
    return numid;
}
