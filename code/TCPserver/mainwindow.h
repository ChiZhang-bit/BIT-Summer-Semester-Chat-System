#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHostInfo>
#include <QMainWindow>
#include <setport.h>
#include "subserver.h"
#include "mysql.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_on_clicked();
    void slot_serverStart();
    void on_pushButton_off_clicked();
    void slot_getIPaddress(QHostInfo info);
    void slot_updateServer(QString);

private:
    Ui::MainWindow *ui;
    setport temp1;
    subserver *server;
};
#endif // MAINWINDOW_H
