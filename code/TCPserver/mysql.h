#ifndef MYSQL_H
#define MYSQL_H

#include <QObject>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QString>
#include <QStringList>
#include <QDebug>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class MySql : public QObject
{
    Q_OBJECT
public:
    static MySql* gethand(){
        if(sqlhand == nullptr){
            sqlhand = new MySql();
        }
        return sqlhand;
    }

    void openDatabase();

    void createTable(QString tablename,
                     QStringList attributelist);

    void create_or_insert_or_drop_Table(QString sqlsentence);

    void insertData(QString tablename,
                    QStringList attributelist,
                    QStringList valuelist);


    bool selectData(QString tablename,
                    QStringList attributelist,
                    QString condition);
    bool selectData(QString sqlsentence,int attributenum);

    void Droptable(QString tablename);

    void DeleteData(QString tablename,
                    QString condition);

    void newConnectuser(int subid, int autoid);

    void disConnectuser(int autoid);

    void UpdateData(QString tablename,
                    QStringList alist,
                    QStringList vlist,
                    QString condition);

    int GetAuto_name(QString tablename, QString name);

    void createtable_sql_exec();

    void create_users_table();

    QString Get_All_Online_usersname(QString tablename);

    void Register_user(QString tablename, QString username, QString password);

    bool verify_user(QString tablename, QString username,QString password);

    bool Select_User(QString tablename, QStringList alist, QStringList vlist);

private:
    explicit MySql(QObject *parent = nullptr);
    static MySql* sqlhand;
    QSqlDatabase database;
    QSqlQuery* sqlquery;
signals:

};

#endif // MYSQL_H
