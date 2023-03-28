#ifndef PRIVATECHATFORM_H
#define PRIVATECHATFORM_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class PrivateChatForm;
}

class PrivateChatForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrivateChatForm(QTcpSocket *tcpsocket, QWidget *parent = nullptr);
    ~PrivateChatForm();
    void setid(QString, QString);

private slots:
    void on_sendButton_clicked();

private:
    Ui::PrivateChatForm *ui;
    QString id;
    QString to_id;
    QTcpSocket *tcpSocket;
};

#endif // PRIVATECHATFORM_H
