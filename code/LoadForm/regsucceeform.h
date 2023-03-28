#ifndef REGSUCCEEFORM_H
#define REGSUCCEEFORM_H

#include <QWidget>

namespace Ui {
class RegSucceeForm;
}

class RegSucceeForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegSucceeForm(QWidget *parent = nullptr);
    ~RegSucceeForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegSucceeForm *ui;
};

#endif // REGSUCCEEFORM_H
