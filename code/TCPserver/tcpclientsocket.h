#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>

class tcpclientsocket : public QTcpSocket
{
    Q_OBJECT
public:
    tcpclientsocket(QObject *parent = 0);

protected slots:
    void receiveData();
    void slot_clientDisconnected();

signals:
    void sig_updateServer(QString);
    void sig_clientDisconnected(int);
    void sig_verusers(QString, QString);
    void sig_regusers(QString, QString);
};

#endif // TCPCLIENTSOCKET_H
