#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    static TCPSocket *gethand() {
        if(sockethand == nullptr) {
            sockethand = new TCPSocket();
        }
        return sockethand;
    }
    void ConnectServer();
    void SendMessage(QString);

private:
    explicit TCPSocket(QObject *parent = nullptr);
    static TCPSocket *sockethand;
    QTcpSocket tcpsocket;

protected slots:
    void receivedata();
    void slotclientdisconnected();

signals:
    void sig_SiginOK();
    void updateserver(QString, int);
    void clientdissconnected(int);
};

#endif // TCPSOCKET_H
