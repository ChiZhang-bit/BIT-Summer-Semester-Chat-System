#ifndef SUBSERVER_H
#define SUBSERVER_H

#include <QTcpServer>
#include <QObject>
#include <QList>
#include "tcpclientsocket.h"
#include "mysql.h"


class subserver : public QTcpServer
{
    Q_OBJECT
public:
    subserver(QObject *parent = 0, QString port = "0");
    QList<tcpclientsocket*> tcpclientsocketlist;
    void deliverMessage(QString, int);
    void deleteItem(int);
    int getNumid();

protected:
    void incomingConnection(int socketDescriptor);

private:
    QTcpServer tcp_server;
    QTcpSocket* tcp_socket;
    QSqlQuery *sqlquery;

protected slots:
    void slot_updateServer(QString);
    void slot_clientDisconnect(int);
    void slot_verifyusers(QString, QString);
    void slot_regusers(QString, QString);

signals:
    void sig_updateServer(QString);
};

#endif // SUBSERVER_H
