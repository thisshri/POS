#include "newuserreg.h"
#include "ui_newuserreg.h"

#include <QMessageBox>


NewUserReg::NewUserReg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUserReg)
{
    ui->setupUi(this);
}

NewUserReg::~NewUserReg()
{
    delete ui;
}

void NewUserReg::on_buttonBox_accepted()
{
    QMessageBox::information(this,
                             tr("New customer window."),
                             tr("Clicked ok")
                             );
}
