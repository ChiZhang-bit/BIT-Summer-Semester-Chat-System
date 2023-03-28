#include "verifyform.h"
#include "ui_verifyform.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QTime>
#include <QtGlobal>

VerifyForm::VerifyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerifyForm)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->setupUi(this);
}

VerifyForm::~VerifyForm()
{
    delete ui;
}

void VerifyForm::paintEvent(QPaintEvent *){
    //qDebug() << "The verification code is generating";
    if(flag) {
        code.clear();
        QPainter painter(this);
        QPen pen;

        /*draw point*/
        for(int i = 0;i < 100;++i) {
            pen = QPen(QColor(qrand()%256,qrand()%256,qrand()%256));
            painter.setPen(pen);
            painter.drawPoint(qrand()%150,qrand()%50);
        }

        /*draw line*/
        for(int i = 0;i < 10;++i) {
                painter.drawLine(qrand()%150,qrand()%50,
                                 qrand()%150,qrand()%50);
        }

        /*Random element*/
        for(int i = 0;i < 4;++i){
            int num = qrand()%3;
            if(num == 0) {
                //number
                code += QString::number(qrand()%10);
            }
            else if(num == 1) {
                //uppercase letter
                int temp = 'A';
                code += static_cast<QChar>(temp + qrand()%26);
            }
            else if(num == 2) {
                //lower case letters
                int temp = 'a';
                code += static_cast<QChar>(temp + qrand()%26);
            }
        }
        pen = QPen(QColor(255,0,0,100));
        QFont font("楷体",25,QFont::Bold,true);
        painter.setFont(font);
        painter.setPen(pen);
        //Draw
        for(int i = 0;i < 4;++i) {
            painter.drawText(10+30*i,5,30,40,Qt::AlignCenter,
                             QString(code[i]));
        }
        flag--;
    }


    //qDebug() << "The verification code has been generated";
}

void VerifyForm::mousePressEvent(QMouseEvent *event) {
    update();
    flag = 1;
}

QString VerifyForm::getcode(){
    return code;
}

