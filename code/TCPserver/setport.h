#ifndef SETPORT_H
#define SETPORT_H

#include <QWidget>

namespace Ui {
class setport;
}

class setport : public QWidget
{
    Q_OBJECT

public:
    explicit setport(QWidget *parent = nullptr);
    ~setport();

private slots:
    void on_pushButton_clicked();

private:
    Ui::setport *ui;
};

#endif // SETPORT_H
