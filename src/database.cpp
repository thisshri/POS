#include "database.h"
#include <QDebug>
#include <QSqlError>
#include <QDir>
#include <QFileSelector>
#include <QFile>
#include <QStandardPaths>
#include <QCoreApplication>

#include <QDateTime>



DataBase::DataBase()
{
/*
    //--------------------------------------locked file modle
    QSqlQueryModel * lockedFileModel = new QSqlQueryModel();
    lockedFileModel->setQuery(*query);
    ui->listView->setModel(lockedFileModel);
    //-------------------------------list locked file query

*/

    // CONNECTING TO DATABASE
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("Database.sqlite");          //path of db is where the path of built is aka exe file.

    if (DB.open()){
    qWarning()<< "Database: Connected.";
    }
    else{
    qWarning()<< "Database: Not connected.";
    }

    //connecting to database.


    qWarning()<<QDateTime::currentDateTime();
    qWarning()<<QDateTime::currentDateTimeUtc();
    qWarning()<<QDateTime::currentMSecsSinceEpoch();


}


/*
bool DataBase::addNewCustomer()
{

}

QVector<QString> DataBase::loadAllVillage(){

}

QVector<QString> DataBase::loadCustName(QString &village){

}

bool DataBase::executeSale(){
    //add the order info in the order table
    //update customer info
    //
}
*/

QString DataBase::getHashedPasswodFormDb(){
    QString hashedPassword;

    QSqlQuery query;
    if( !query.exec("SELECT HashedPassword FROM Login;") )
    {
        qWarning() << query.lastError().text();
    }else{
        while (query.next()) {
            hashedPassword = query.value(0).toString();
        }

    }
    return hashedPassword;
}//getHashedPasswordFromDb


bool DataBase::LogIn(QString loginHashedPassword,
                                QString gPrice,
                                QString sPrice)
{
    //getting the hashed password from db and comparing it with the enterd password
    if (loginHashedPassword == this->getHashedPasswodFormDb()){
        qWarning()<<loginHashedPassword<<" == "<<this->getHashedPasswodFormDb();
    }else{
        return false;
    }

    // gold silve and last login
    bool status = false;


    QSqlQuery query;
    QString queryString = "UPDATE Login SET GoldPrice='"+gPrice+"',SilverPrice='"+sPrice+"',LastLoginTime=DATETIME('now','localtime');";

    if( !query.exec(queryString)){//if any error occurs following will run. and the stauts will return false.
        qWarning() << query.lastError().text();
    }else{
        status = true;
    }
    qWarning()<<"LAST ERROR"<<query.lastError().text();
    qWarning()<<"LAST QUERY"<<query.lastQuery();
    qWarning()<<gPrice.toDouble();
    qWarning()<<sPrice.toDouble();

    return status;
}//logIn


QString DataBase::getLastLoginTime(){

    QString loginTime = "E: loading time.";


    QSqlQuery query;
    if( !query.exec("SELECT LastLoginTime FROM Login;") )
    {
        qWarning() << query.lastError().text();
    }else{
        while (query.next()) {
            loginTime = query.value(0).toString();
        }

    }

    return loginTime;
}


QVector<QString> DataBase::getAllVillages(){     //get all village function
    QVector<QString> villageVector;
    QSqlQuery query;
    query.exec("SELECT Village FROM customer GROUP BY village ");
    while (query.next()) {
        villageVector.append(query.value(0).toString());
    }

    return villageVector;

}


QVector<QString> DataBase::getAllNames(QString villageName){     //get all village function
    QVector<QString> nameVector;
    QSqlQuery query;
    query.exec("SELECT Name FROM customer WHERE Village == '"+villageName+"'");
    while (query.next()) {
        nameVector.append(query.value(0).toString());
    }

    return nameVector;

}


bool DataBase::addNewCustomer(QString mobileNo, QString name, QString otherName, QString village){
    //balance for new customer when created is zero.
    QSqlQuery query;
    QString queryString =
            "INSERT INTO Customer (Balance,MobileNo,Name,OtherName,Village) VALUES ('0','"+mobileNo+"','"+name.toUpper()+"','"+otherName.toUpper()+"','"+village.toUpper()+"');";
    return query.exec(queryString);
}// addNewCustomer

