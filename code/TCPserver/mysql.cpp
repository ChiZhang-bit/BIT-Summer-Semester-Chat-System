#include "mysql.h"
#include <QCoreApplication>
MySql* MySql::sqlhand = nullptr;

MySql::MySql(QObject *parent) : QObject(parent)
{

}

void MySql::openDatabase(){
    if(QSqlDatabase::contains("qt_sql_dafault_connection")){
        database = QSqlDatabase::database("qt_sql_dafault_connection");
    }
    else{
        database = QSqlDatabase::addDatabase("QSQLITE");
        QString dbPath = QCoreApplication::applicationDirPath() + "//Instant_chat_system.db";
        qDebug()<<dbPath;
        database.setDatabaseName(dbPath);
        database.setUserName("root");
        database.setPassword("123456");
    }

    if(database.open()){
        sqlquery = new QSqlQuery(database);
        qDebug()<<"database is running";
    }
    else{
        qDebug()<<"database open failed :";
    }

}

void MySql::createTable(QString tablename, QStringList attributelist){
    //tablename 为创建表的名字
    //attributelist 为属性的列表
    QString create = "Create table " + tablename + "(";
    for(int i=0 ; i< attributelist.count() ; i++){
        create += attributelist.at(i);
        if(i != attributelist.count() - 1) create += ", ";
    }
    create += ")";
    qDebug()<< create;

    if(sqlquery->prepare(create)){
        if(sqlquery->exec()){
            qDebug()<<"create userstable OK";
        }
    }
    else{
        qDebug() << "create error!" << sqlquery->lastError();
    }
}

void MySql::create_or_insert_or_drop_Table(QString sqlsentence){
    if(sqlquery->prepare(sqlsentence)){
        if(sqlquery->exec()){
            qDebug()<<"OK";
        }
    }
    else{
        qDebug() << "sentence error!" << sqlquery->lastError();
    }
}

void MySql::insertData(QString tablename,
                       QStringList attributelist,
                       QStringList valuelist){
    QString insert = "Insert into " + tablename + "(";

    {
        int anum = attributelist.count();
        int vnum = valuelist.count();

        if(anum != vnum){
            qDebug()<<"textlist error";
            return;
        }

        for(int i = 0; i < anum ;i++){
            insert += attributelist.at(i);
            if(i != anum - 1) insert += ", ";
        }

        insert +=") Values(";
        for(int i = 0; i < vnum; i++){
            insert += valuelist.at(i);
            if(i != vnum - 1) insert+= ",";
        }
        insert += ")";
        qDebug()<< insert;
    }

     if(sqlquery->prepare(insert)){
         if(sqlquery->exec()){
             qDebug()<<"insert userstable OK";
         }
         else{
             qDebug()<<"insert table command error:" << sqlquery->lastError();
         }
     }
     else{
         qDebug()<<"insert table command error!";
     }

}

bool MySql::selectData(QString tablename,
                       QStringList attributelist,
                       QString condition){
    QString select = "Select ";
    for(int i = 0;i < attributelist.count();i++){
        select += attributelist.at(i);
        if(i != attributelist.count() - 1) select += ",";
    }
    select += " FROM ";
    select += tablename;
    if(!condition.isEmpty()){
        select += " where";
        select += condition;
    }
    qDebug()<<select;

    if(sqlquery->prepare(select)){
        if(sqlquery->exec()){
            while(sqlquery->next()){
                for(int i = 0 ;i < attributelist.count() ; i++){
                    qDebug()<<sqlquery->value(i).toString();
                }
            }
            return true;
        }
        else{
            qDebug()<<"select table command error!";
            return false;
        }
    }
    else{
        qDebug()<<"select table command error!";
        return false;
    }
}

bool MySql::selectData(QString sqlsentence,
                       int attributenum){

    if(sqlquery->prepare(sqlsentence)){
        if(sqlquery->exec()){
            while(sqlquery->next()){
                for(int i = 0 ;i < attributenum ; i++){
                    qDebug()<<sqlquery->value(i).toString();
                }
            }
            return true;
        }
        else{
            qDebug()<<"select table command error!";
            return false;
        }
    }
    else{
        qDebug()<<"select table command error!";
        return false;
    }
}

void MySql::Droptable(QString tablename){
    QString str_drop="DROP TABLE "+ tablename;
    if(sqlquery->prepare(str_drop)){
        if(sqlquery->exec()){
            qDebug()<<"Drop Success";
        }
    }
    else{
        qDebug()<<"Drop failed";
    }
}

void MySql::DeleteData(QString tablename, QString condition){
    QString str_delete = "Delete from " + tablename;
    if(!condition.isEmpty()){
        str_delete += " where ";
        str_delete += condition;
    }
    qDebug()<<str_delete;

    if(sqlquery->prepare(str_delete)){
        if(sqlquery->exec()){
            qDebug()<<"DeleteSuccess";
        }
    }
    else{
        qDebug()<<"Delete failed";
    }
}

void MySql::newConnectuser(int subid, int autoid){
    QString tablename = "Online_user";
    QStringList alist;
    alist.append("sub_id");
    alist.append("autoid");

    QStringList vlist;

    vlist.append(QString::number(subid,10));
    vlist.append(QString::number(autoid,10));
    this->insertData(tablename,alist,vlist);
}

void MySql::disConnectuser(int autoid){
    QString tablename = "Online_user";
    QString condition = "autoid =";

    condition += QString::number(autoid,10);

    this->DeleteData(tablename,condition);
}

void MySql::UpdateData(QString tablename,
                       QStringList alist,
                       QStringList vlist,
                       QString condition){
    QString update = "UPDATE " + tablename +" SET ";

    if(alist.count()!=vlist.count()){
        qDebug()<<"error command update";
    }

    for(int i=0; i< alist.count();i++){
        update += alist.at(i);
        update += "=";
        update += vlist.at(i);
        update += " ";
        if(i != alist.count() - 1) update += ", ";
    }

    if(!condition.isEmpty()){
        update += " where ";
        update += condition;
    }

    qDebug() << update ;

    if(sqlquery->prepare(update)){
        if(sqlquery->exec()){
            qDebug()<<"Update Success";
        }
    }
    else{
        qDebug()<<"Update failed";
    }
}

int MySql::GetAuto_name(QString tablename, QString name){
    QString select = "select autoid from " + tablename + " where " + "username = ";
    select += "'" ;
    select += name;
    select += "'";
    qDebug()<<select;

    if(sqlquery->prepare(select)){
        if(sqlquery->exec()){
            while(sqlquery->next()){
                return sqlquery->value(0).toInt();
            }
            qDebug()<<"NONE";
            return false;
        }
        else{
            qDebug()<<"select table command error!";
            return false;
        }
    }
    else{
        qDebug()<<"select table command error!";
        return false;
    }
}

QString MySql::Get_All_Online_usersname(QString tablename){
    QString get_username = "select username from " + tablename;

    QStringList res;

    if(sqlquery->prepare(get_username)){
        if(sqlquery->exec()){
            while(sqlquery->next()){
                res.append(sqlquery->value(0).toString());
            }
            qDebug()<<"get all online username success";
        }
        else{
            qDebug()<<"select table command error!";
        }
    }
    else{
        qDebug()<<"select table command error!";
    }

    QString ans;
    QChar split = '[';

    for(int i=0;i<res.count();i++){
        qDebug() << res.at(i);
        ans += res.at(i);
        if(i != res.count() - 1)ans += split;
    }

    qDebug()<<ans;
    return ans;
}

void MySql::createtable_sql_exec(){
    this->openDatabase();

    QString tablename = "Online_user";
    QStringList tablelist;
    tablelist.append("sub_id int UNIQUE");
    tablelist.append("autoid int UNIQUE");
    tablelist.append("username text");
    this->createTable(tablename,tablelist);

}

void MySql::create_users_table(){
    this->openDatabase();

    QString allusertable = "Users" ;
    QStringList alist;

    alist.append("username text UNIQUE");
    alist.append("password VARCAHR(100) NOT NULL");
    this->createTable(allusertable,alist);
}

void MySql::Register_user(QString tablename, QString username, QString password){
    QStringList alist;
    alist.append("username");
    alist.append("password");
    this->openDatabase();

    QStringList vlist;
    QString str_username = "'" + username + "'";
    QString str_password = "'" + password + "'";

    vlist.append(str_username);
    vlist.append(str_password);

    this->insertData(tablename,alist,vlist);
}

bool MySql::Select_User(QString tablename, QStringList alist, QStringList vlist){
    this ->openDatabase();

    QString select = "select * from " + tablename + " where ";
    for(int i=0;i<alist.count();i++){
        select += alist.at(i);
        select += "=";
        select += vlist.at(i);
        if(i != alist.count() - 1) select += " AND ";
    }
    qDebug()<<select;

    if(sqlquery->prepare(select)){
        if(sqlquery->exec()){
            while(sqlquery->next()){
                return true;
            }
            return false;
        }
        else{
            qDebug()<<"select table command error!";
            return false;
        }
    }
    else{
        qDebug()<<"select table command error!";
        return false;
    }
}

bool MySql::verify_user(QString tablename, QString username, QString password){
    this->openDatabase();

    QString str_username = "'" + username + "'";
    QString str_password = "'" + password + "'";

    QStringList alist;
    alist.append("username");
    alist.append("password");

    QStringList vlist;
    vlist.append(str_username);
    vlist.append(str_password);

    return this->Select_User(tablename,alist,vlist);
}
