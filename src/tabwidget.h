#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QComboBox>
#include <database.h>




namespace Ui {
class TabWidget;
}

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit TabWidget(QWidget *parent = 0);

    ~TabWidget();

private slots:
    void on_cbVillage_currentTextChanged(const QString &arg1);

    void on_pbAddNewCustomer_clicked();

    void on_cbSelectVillage_currentTextChanged(const QString &arg1);

private:
    Ui::TabWidget *ui;

    DataBase db;



};

#endif // TABWIDGET_H
