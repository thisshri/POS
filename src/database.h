#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVector>
#include <QSqlQueryModel>


class DataBase
{
private:
    QSqlDatabase DB;
public:
    DataBase();

    bool addNewCustomer(QString mobileNo, QString name, QString otherName, QString village);
    QVector<QString> getAllVillages();
    QVector<QString> loadCustName(QString &village);

    QVector<QString> getAllNames(QString villageName);


    bool executeSale();

    QString getHashedPasswodFormDb();
    bool LogIn(QString loginHashedPassword,
               QString gPrice,
               QString sPrice);

    QString getLastLoginTime();


};

#endif // DATABASE_H
