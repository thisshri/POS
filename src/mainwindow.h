#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    DataBase db;

private slots:

    void on_pbLogin_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
