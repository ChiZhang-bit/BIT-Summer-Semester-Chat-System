#include "regsucceeform.h"
#include "ui_regsucceeform.h"

RegSucceeForm::RegSucceeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegSucceeForm)
{
    ui->setupUi(this);
}

RegSucceeForm::~RegSucceeForm()
{
    delete ui;
}

void RegSucceeForm::on_pushButton_clicked()
{
    this->close();
}
