#include "gameend.h"
#include "ui_gameend.h"

GameEnd::GameEnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameEnd)
{
    ui->setupUi(this);
}

GameEnd::~GameEnd()
{
    delete ui;
}

void GameEnd::on_endButton_clicked()
{
    this->close();
}
