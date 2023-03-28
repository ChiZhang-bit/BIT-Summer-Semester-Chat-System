#include "regfailform.h"
#include "ui_regfailform.h"

RegFailForm::RegFailForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegFailForm)
{
    ui->setupUi(this);
}

RegFailForm::~RegFailForm()
{
    delete ui;
}
