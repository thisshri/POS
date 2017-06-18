#ifndef NEWUSERREG_H
#define NEWUSERREG_H

#include <QDialog>

namespace Ui {
class NewUserReg;
}

class NewUserReg : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserReg(QWidget *parent = 0);
    ~NewUserReg();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::NewUserReg *ui;
};

#endif // NEWUSERREG_H
