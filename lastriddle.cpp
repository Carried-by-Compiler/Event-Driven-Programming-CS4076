#include "lastriddle.h"
#include "ui_lastriddle.h"
#include <iostream>

LastRiddle::LastRiddle(QWidget *parent, QString *a) :
    QDialog(parent),
    ui(new Ui::LastRiddle)
{
    this->a = a;
    ui->setupUi(this);
    ui->riddleQuestion->setText("I will disappear everytime you say my name. What am I?");
}

LastRiddle::~LastRiddle()
{
    std::cout << "Deleting Last Riddle Object" << std::endl;
    delete ui;
}

void LastRiddle::on_riddleSubmit_clicked()
{
    *a = ui->riddleAnswer->text();
    this->close();
}

void LastRiddle::on_riddleAnswer_returnPressed()
{
    *a = ui->riddleAnswer->text();
    this->close();
}
