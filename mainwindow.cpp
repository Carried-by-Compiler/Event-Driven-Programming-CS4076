#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    QPixmap p(":/images/star.png");
    ui->mapImage->setPixmap(p);
    displayCurrentRoomInfo();
    displayExitList();
    floorMoveAllowed();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::floorMoveAllowed() {
    bool up = zork->canGoUpstairs();
    bool down = zork->canGoDownstairs();

    if (!up) {
        ui->upButton->setEnabled(false);
    } else {
        ui->upButton->setEnabled(true);
    }

    if (!down) {
        ui->downButton->setEnabled(false);
    } else {
        ui->downButton->setEnabled(true);
    }
}

void MainWindow::displayCurrentRoomInfo() {
    QString currentRoomInfo;
    Room *room;
    Floor *floor;
    floor = zork->getCurrentFloor();
    room = zork->getCurrentRoom();

    currentRoomInfo = room->longDescription();
    ui->roomInfoOutput->document()->setPlainText(floor->getDesc() + currentRoomInfo);
    ui->roomNameLabel->setText(room->shortDescription());
}

void MainWindow::displayExitList() {
    Room *currRoom = zork->getCurrentRoom();
    vector<Room*> exits = currRoom->getExits();

    for (int i = 0; i < exits.size(); i++) {
        ui->listWidget->addItem(exits.at(i)->shortDescription());
    }
}
/*void MainWindow::check_exit_rooms(){
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
} */

/*void MainWindow::on_teleButton_clicked()
{
    zork->goTeleport();
    //check_exit_rooms();
    ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
} */

/*void MainWindow::on_startButton_clicked()
{
   ui->textLabel->setText(QString::fromStdString(zork->getCurrentRoom()->longDescription()));
} */

/*void MainWindow::on_mapButton_clicked()
{
    ui->textLabel->setText(QString::fromStdString(zork->getMap()));
} */

/*void MainWindow::on_NorthButton_clicked()
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
}*/

/*void MainWindow::on_testButton_clicked()
{
    ui->textLabel->setText(QString::fromStdString("hello"));
} */

void MainWindow::on_goButton_clicked()
{
    if(ui->listWidget->selectedItems().size() != 0) {
        QString selectExit = ui->listWidget->currentItem()->text();
        zork->go(selectExit);

        displayCurrentRoomInfo();
        clearExitList();
        floorMoveAllowed();
    }
}

void MainWindow::clearExitList() {
    ui->listWidget->clear();
    displayExitList();
}

void MainWindow::on_upButton_clicked()
{
    zork->moveFloorUp();
    displayCurrentRoomInfo();
    clearExitList();
    floorMoveAllowed();
}

void MainWindow::on_downButton_clicked()
{

    zork->moveFloorDown();
    displayCurrentRoomInfo();
    clearExitList();
    floorMoveAllowed();
}
