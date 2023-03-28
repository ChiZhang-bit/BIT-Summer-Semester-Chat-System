#include "tcpserver.h"

#include <QDebug>

tcpserver* tcpserver::serverhand = nullptr;
tcpserver::tcpserver(QObject *parent) : QObject(parent)
{
    hostInfo.setHostName(hostInfo.localHostName());
    hostInfo.lookupHost(hostInfo.localHostName(),
                        this,
                        SLOT(slot_getAddress(QHostInfo)));
}

void tcpserver::slot_getAddress(QHostInfo info){
    emit sig_getIPaddress(info);
}

void tcpserver::getPort(QString port){
    serverport = port;
    emit sig_setportOK();
}

QString tcpserver::passPort(){
    return serverport;
}
