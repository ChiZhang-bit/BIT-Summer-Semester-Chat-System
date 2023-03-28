#include "tcpsocket.h"

TCPSocket *TCPSocket::sockethand = nullptr;
TCPSocket::TCPSocket(QObject *parent) : QObject(parent)
{
    connect(this, &TCPSocket::readyRead, this, &TCPSocket::receivedata);
    connect(this, &TCPSocket::disconnect, this, &TCPSocket::slotclientdisconnected);
}

void TCPSocket::ConnectServer() {
    tcpsocket.connectToHost("192.168.43.148", 5566);
    qDebug() << "Port : " << tcpsocket.localPort();
}

void TCPSocket::SendMessage(QString mes) {
    tcpsocket.write(mes.toLatin1());
}

void TCPSocket::receivedata(){
    int length = 10;
    QByteArray array = tcpsocket.readAll();
    QString msg = array;
    emit updateserver(msg, length);
}

void TCPSocket::slotclientdisconnected(){
    emit clientdissconnected(this->socketDescriptor())
}
