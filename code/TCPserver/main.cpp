#include "mainwindow.h"
#include "mysql.h"
#include <QApplication>

void createtable_sql_exec(MySql* sqlconnect);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MySql* sqlconnect = MySql::gethand();

    //firsttime RUN：
    sqlconnect -> createtable_sql_exec();
    sqlconnect -> create_users_table();

    sqlconnect->openDatabase();
    sqlconnect->Register_user("Users","魏慧聪123","1120313123");

    if(sqlconnect->verify_user("Users","魏慧聪","1120313123")== false){
        qDebug()<<"OK";
    }
    else{
        qDebug()<<"YES";
    }


    MainWindow w;
    w.show();

    QString condition = "";
    sqlconnect -> DeleteData("Online_user", condition);



    return a.exec();
}

