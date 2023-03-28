#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QTextCharFormat>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
#include "privatechatform.h"
#include <QTime>

namespace Ui {
class TcpClient;
}
class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void SetId(QString);
    void SetIdText(QString);

private:
    QString id;
    QString ip;
    bool status;
    int port;
    Ui::TcpClient *ui;
    PrivateChatForm *privatechatform;
    QHostAddress *serverIP;
    QTcpSocket *tcpSocket;
    QStringList res;
    QString currentObject;

private slots:
    void slot_Connected();
    void slot_Disconnected();
    void slot_dataReceived();
    void on_enterBtn_clicked();
    void on_sendBtn_clicked();
    //void solt_ShowOnlineUsers();
    void on_listViewOnline_doubleClicked(const QModelIndex &index);
    void on_pushButtonFont_clicked();
    void on_pushButtonColor_clicked();
};

#endif // TCPCLIENT_H
