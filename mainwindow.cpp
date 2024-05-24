#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("/home/vision/demo.db");

    if(!mydb.open())
        ui->label->setText("database is not connected");
    else {
        ui->label->setText("Connected.......");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

