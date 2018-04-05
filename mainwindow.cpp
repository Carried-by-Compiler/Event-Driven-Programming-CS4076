#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zork = new ZorkUL();
    QPixmap p(":/maps/ground_hallway.png");
    ui->mapImage->setPixmap(p);
    displayCurrentRoomInfo();
    displayExitList();
    inventoryDisplay();
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
    QString roomViewPath;
    Room *room;
    Floor *floor;
    floor = zork->getCurrentFloor();
    room = zork->getCurrentRoom();
    currentRoomInfo = room->longDescription();
    ui->roomInfoOutput->document()->setPlainText(floor->getDesc() + currentRoomInfo);
    roomViewPath = room->getViewPixmap();
    ui->roomNameLabel->setPixmap(roomViewPath);

}
void MainWindow::inventoryDisplay(){
    QString info = ":/items/Inventory_Image.jpg";
    ui->inventoryDisplay->setPixmap(info);
    /*
    notes *note;
    note = zork->getCurrentNote();
    QString path = note->getimagePath();
    ui->item1->setPixmap(path);
    */

}
void MainWindow::displayExitList() {
    Room *currRoom = zork->getCurrentRoom();
    vector<Room*> exits = currRoom->getExits();

    for (int i = 0; i < exits.size(); i++) {
        bool check = exits.at(i)->checkIfLocked();
        if(!check){
        ui->listWidget->addItem(exits.at(i)->shortDescription());
        }
        else{
            ui->listWidget->addItem("?????");
        }
    }
}

void MainWindow::on_goButton_clicked()
{
    if(ui->listWidget->selectedItems().size() != 0) {
        QString selectExit = ui->listWidget->currentItem()->text();
        if(selectExit== "?????"){
          ui->roomInfoOutput->document()->setPlainText("Locked door, find key");
        }
        else{
        ui->mapImage->setPixmap(zork->go(selectExit));

        displayCurrentRoomInfo();
        clearExitList();
        floorMoveAllowed();
        }
    }
}

void MainWindow::clearExitList() {
    ui->listWidget->clear();
    displayExitList();
}

void MainWindow::on_upButton_clicked()
{
    ui->mapImage->setPixmap(zork->moveFloorUp());
    displayCurrentRoomInfo();
    clearExitList();
    floorMoveAllowed();
}

void MainWindow::on_downButton_clicked()
{

    ui->mapImage->setPixmap(zork->moveFloorDown());
    displayCurrentRoomInfo();
    clearExitList();
    floorMoveAllowed();
}

void MainWindow::on_SearchButton_clicked()
{
    vector<Item*> items = zork->getCurrentRoom()->getItems();
    if(items.size() == 0) {
        ui->roomInfoOutput->document()->setPlainText("Nothing found");
    } else {
        for(int i = 0; i < items.size(); i++) {
            if(items.at(i)->getShortDescription().compare("NOTE") == 0) {
                ui->roomInfoOutput->setPlainText("A note has been added to your inventory.\n");
            } else if (items.at(i)->getShortDescription().compare("KEY") == 0) {
                ui->roomInfoOutput->setPlainText("A key has been added to your inverntory.\n");
            }

            // Add item to inventory
            // Display item on the UI
        }
    }
}

void MainWindow::on_UseItem_clicked()
{
      ui->roomInfoOutput->document()->setPlainText("Nothing to use on");
}
