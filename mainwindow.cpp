#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::check_exit_rooms(){
    if(zork->getCurrentRoom()->nextRoom("north")== NULL){
        ui->NorthButton->setEnabled(false);
    }
    if(!(zork->getCurrentRoom()->nextRoom("north")== NULL)){
        ui->NorthButton->setEnabled(true);
    }
    if(zork->getCurrentRoom()->nextRoom("south")== NULL){
        ui->SouthButton->setEnabled(false);
    }
    if(!(zork->getCurrentRoom()->nextRoom("south")== NULL)){
        ui->SouthButton->setEnabled(true);
    }

    if(zork->getCurrentRoom()->nextRoom("west")== NULL){
        ui->westButton->setEnabled(false);
    }
    if(!(zork->getCurrentRoom()->nextRoom("west")== NULL)){
        ui->westButton->setEnabled(true);
    }
    if(zork->getCurrentRoom()->nextRoom("east")== NULL){
        ui->EastButton->setEnabled(false);
    }
    if(!(zork->getCurrentRoom()->nextRoom("east")== NULL)){
        ui->EastButton->setEnabled(true);
    }
}

void MainWindow::on_teleButton_clicked()
{
    zork->goTeleport();
    check_exit_rooms();
    ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_startButton_clicked()
{
   ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_mapButton_clicked()
{
    ui->textLabel->setText(QString::fromStdString(zork->getMap()));
}

void MainWindow::on_NorthButton_clicked()
{
    zork->go("north");
    check_exit_rooms();
    ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_westButton_clicked()
{
   zork->go("west");
   check_exit_rooms();
   ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_EastButton_clicked()
{
    zork->go("east");
    check_exit_rooms();
    ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_SouthButton_clicked()
{
    zork->go("south");
    check_exit_rooms();
    ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
}

void MainWindow::on_testButton_clicked()
{
    ui->textLabel->setText(QString::fromStdString("hello"));
}
