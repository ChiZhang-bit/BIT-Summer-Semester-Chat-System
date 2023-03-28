#ifndef REGFAILFORM_H
#define REGFAILFORM_H

#include <QWidget>

namespace Ui {
class RegFailForm;
}

class RegFailForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegFailForm(QWidget *parent = nullptr);
    ~RegFailForm();

private:
    Ui::RegFailForm *ui;
};

#endif // REGFAILFORM_H
