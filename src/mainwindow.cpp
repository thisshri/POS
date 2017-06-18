#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <tabwidget.h>
#include <QDebug>
#include <QLineEdit>
#include <QFont>
#include <QLineEdit>
#include <QValidator>
#include <QRegExpValidator>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <database.h>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    QFont font;
    font.setPixelSize(14);
    this->setFont(font);
*/
    ui->lePassword->setEchoMode(QLineEdit::Password);

    statusBar()->showMessage("LAST LOGIN TIME: "+db.getLastLoginTime());


}//constructor

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbLogin_clicked()
{

    //
    QString enteredHashedPassword = QString("%1").arg
            (QString(QCryptographicHash::hash(ui->lePassword->text().toUtf8(),QCryptographicHash::Sha1).toHex()));


    if (/*db.LogIn(enteredHashedPassword,ui->leGoldPrice->text(),ui->leSilverPrice->text())*/true){

        TabWidget * tabWidget = new TabWidget;
        tabWidget->show();

    }else{
        //show message box to enter pass, gold or silver.
    }

    //Clearing password field after loging in.
    ui->lePassword->clear();
    statusBar()->messageChanged(db.getLastLoginTime());
}
