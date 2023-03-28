#ifndef VERIFYFORM_H
#define VERIFYFORM_H

#include <QWidget>
//#include "tcpclient.h"

namespace Ui {
class VerifyForm;
}

class VerifyForm : public QWidget
{
    Q_OBJECT

public:
    explicit VerifyForm(QWidget *parent = nullptr);
    ~VerifyForm();
    QString getcode();

private slots:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);


private:
    Ui::VerifyForm *ui;
    //MainWindow *mainwindow;
    QString code;
    int flag = 2;
};

#endif // VERIFYFORM_H
