#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>

class tcpserver : public QObject
{
    Q_OBJECT
public:
    static tcpserver* gethand(){
        if (serverhand == nullptr)
            serverhand = new tcpserver();
        return serverhand;
    }
    void getPort(QString);
    QString passPort();

private:
    explicit tcpserver(QObject *parent = nullptr);
    static tcpserver* serverhand;
    QHostInfo hostInfo;
    //QTcpServer tcp_server;
    //QTcpSocket* tcp_socket;
    QString serverport;

private slots:
    void slot_getAddress(QHostInfo info);

signals:
    void sig_setportOK();
    void sig_getIPaddress(QHostInfo info);
};

#endif // TCPSERVER_H
