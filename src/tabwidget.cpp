#include "tabwidget.h"
#include "ui_tabwidget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFormLayout>
#include "newuserreg.h"
#include <QSqlQueryModel>

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);

    ui->cbVillage->addItems(db.getAllVillages().toList());

    //mem leak here
    QSqlQueryModel * asdf = new QSqlQueryModel;
    asdf->setQuery("SELECT Name, Village, Balance, MobileNo, OtherName FROM Customer");
    ui->tvBalance->setModel(asdf);



    ui->cbSelectVillage->addItems(db.getAllVillages().toList());


}

TabWidget::~TabWidget()
{
    delete ui;
}


void TabWidget::on_cbVillage_currentTextChanged(const QString &arg1)
{

    ui->cbName->clear();
    ui->cbName->addItems(db.getAllNames(arg1).toList());
}

void TabWidget::on_pbAddNewCustomer_clicked()
{



    NewUserReg * userReg = new NewUserReg;
    userReg->show();

    //adding signal to call cb village current text change
    //update village combo.
}

void TabWidget::on_cbSelectVillage_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * queryModel = new QSqlQueryModel;
    queryModel->setQuery("SELECT Name, Village, Balance, MobileNo, OtherName FROM Customer WHERE Village == '"+arg1+"'");
    ui->tvBalance->setModel(queryModel);
}
