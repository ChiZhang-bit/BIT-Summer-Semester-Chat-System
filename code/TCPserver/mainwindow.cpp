#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpserver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpserver* tcp = tcpserver::gethand();
    connect(tcp,
            SIGNAL(sig_setportOK()),
            this,
            SLOT(slot_serverStart()));
    connect(tcp,
            SIGNAL(sig_getIPaddress(QHostInfo)),
            this,
            SLOT(slot_getIPaddress(QHostInfo)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_on_clicked()
{
    temp1.setGeometry(860,480,200,120);
    temp1.show();
}

void MainWindow::slot_serverStart()
{
    tcpserver *tcp = tcpserver::gethand();

    ui->label->setText("服务器运行中……");
    ui->pushButton_on->setText("服务已开启");
    ui->pushButton_on->setEnabled(false);

    server = new subserver(this, tcp->passPort());
    connect(server,
            &subserver::sig_updateServer,
            this,
            &MainWindow::slot_updateServer);
}

void MainWindow::on_pushButton_off_clicked()
{
    close();
}

void MainWindow::slot_getIPaddress(QHostInfo info){
    QList<QHostAddress> addlist = info.addresses();
    if(addlist.count()>0){
        for(int i=addlist.count()-1; i>=0; i--){
            ui->comboBox->addItem(addlist.at(i).toString());
        }
    }
}

void MainWindow::slot_updateServer(QString msg)
{

    if(msg[0] == ':')
    {
        int i=3;
        int id=0;
        int Aauto=0;
        int Bauto=0;

        QString clientA = "";
        while(msg[i] != ']')
        {
            clientA += msg[i++];
        }
        //qDebug()<<"clientA's username:  "<<clientA;

        if(msg[1] == 'S')
        {
            QString clientB = "";
            i+=2;
            while(msg[i] != ']')
            {
                clientB += msg[i++];
            }
            //qDebug()<<"clientB's username:  "<<clientB;

            // already clientB' NAME get clientB's auto
            MySql* sqlconnect = MySql::gethand();
            sqlconnect->openDatabase();

            Bauto = sqlconnect->GetAuto_name("Online_user",clientB);
            //----------------------------------------------
        }

        QString true_msg = clientA;
        i++;
        while(i < msg.length())
        {
            true_msg += msg[i++];
        }

        ui->textEdit->append(true_msg);

        if(msg[1] == 'S')
        {
            true_msg = "$" + true_msg + "$";
            server->deliverMessage(true_msg, Bauto);
        }

        if(msg[1] == 'E')
        {
            id = server->getNumid();
        //-------------------------------------------------------
            MySql* sqlconnect = MySql::gethand();
            sqlconnect->openDatabase();

            QStringList alist, vlist;
            alist.append("username");

            QString name = "'" + clientA + "'";
            vlist.append(name);

            QString condition = "sub_id =";
            condition += QString::number(id);

            sqlconnect->UpdateData("Online_user",alist,vlist,condition);

            QString currentList = sqlconnect->Get_All_Online_usersname("Online_user");
            QString list_msg = "*" + currentList;

            server->deliverMessage(list_msg, -2);
        //--------------------------------------------------------

        }

        if(msg[1] == 'L')
        {
            // already clientA' NAME get clientA's auto
            MySql* sqlconnect = MySql::gethand();
            sqlconnect->openDatabase();

            Aauto = sqlconnect->GetAuto_name("Online_user",clientA);
            qDebug() << "select get: "<< sqlconnect->GetAuto_name("Online_user",clientA);
            server->deleteItem(Aauto);
            // --------------------------------------------------
        }
    }
    else
    {
        //qDebug()<<"autoinfo!";
        ui->textEdit->append(msg);
    }
}
