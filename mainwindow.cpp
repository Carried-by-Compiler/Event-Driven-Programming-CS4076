#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    inventoryItemCounter = 1;
    QString message = "<html><h3>Game Objective</h3>The front door of the building";
    message += " is locked. You must find the key as well as solve the riddle";
    message += " in order to escape. Notes around the house may help you, so search for them.</html>";

    ui->setupUi(this);
    zork = new ZorkUL();
    QPixmap p(":/maps/ground_hallway.png");
    ui->mapImage->setPixmap(p);

    notes *n = new notes("NOTE", "Hallway", message, ":/items/Page_image.png");
    addItemToInventoryGUI(n);
    ui->roomInfoOutput->document()->setHtml(n->getContents());

    displayCurrentRoomInfo();
    displayExitList();
    inventoryDisplay();
    floorMoveAllowed();
    ui->roomInfoOutput->document()->setHtml(n->getContents());
}

MainWindow::~MainWindow()
{
    delete zork;
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
        } else if(selectExit == "Front Door") {
            displayLastRiddle();
        } else{
        ui->mapImage->setPixmap(zork->go(selectExit));

        displayCurrentRoomInfo();
        clearExitList();
        floorMoveAllowed();
        }
    }
}
void MainWindow::on_unlocked_Door(QString curRoom, int itemNumber)
{
    ui->mapImage->setPixmap(zork->go(curRoom));
    clearExitList();
    floorMoveAllowed();
    //inventoryItems.erase(inventoryItems.begin() + itemNumber);
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
    QString output = "";
    vector<Item*> items = zork->getCurrentRoom()->getItems();
    if(items.size() == 0) {
        ui->roomInfoOutput->document()->setPlainText("Nothing found");
    } else {
        for(int i = 0; i < items.size(); i++) {
            if(items.at(i)->getShortDescription().compare("NOTE") == 0) {
                //ui->roomInfoOutput->setPlainText("A note has been added to your inventory.\n");
                output += "A note has been added to your inventory.\n";
                notes *foundNote = (notes *) items.at(i);

                zork->addNote(foundNote);

                addItemToInventoryGUI(foundNote);
                /*
                QPixmap p(foundNote->getimagePath());
                QIcon buttonIcon(p);
                ui->item1->setIcon(buttonIcon);
                ui->item1->setIconSize(p.rect().size());
                ui->item1->setPlainText(foundNote->getNoteID());
                */
            } else if (items.at(i)->getShortDescription().compare("KEY") == 0) {               
                output += "A key added to Inventory\n";
                keys *foundKey = (keys *) items.at(i);
                zork->addKeys(foundKey);
                 addItemToInventoryGUI(foundKey);
            }
            ui->roomInfoOutput->document()->setPlainText(output);
            // Add item to inventory
            // Display item on the UI
        }

        // clear room of items
           zork->getCurrentRoom()->clearRoomOfItems();
    }
}

void MainWindow::addItemToInventoryGUI(Item *item) {
    if(item->getShortDescription().compare("NOTE") == 0) {
        inventoryItems.push_back(item);
        notes* note = (notes *)item;
        insertToGUI(note);

    } else if(item->getShortDescription().compare("KEY") == 0) {
        inventoryItems.push_back(item);
        keys* key = (keys *)item;
        insertToGUI(key);
    }
}

void MainWindow::insertToGUI(notes *n) {
    QPixmap p(n->getimagePath());
    QIcon buttonIcon(p);

    switch (inventoryItemCounter) {
    case 1:
        ui->item1->setText(n->getNoteID());
        ui->item1->setIcon(buttonIcon);
        ui->item1->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 2:
        ui->item2->setText(n->getNoteID());
        ui->item2->setIcon(buttonIcon);
        ui->item2->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 3:
        ui->item3->setText(n->getNoteID());
        ui->item3->setIcon(buttonIcon);
        ui->item3->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 4:
        ui->item4->setText(n->getNoteID());
        ui->item4->setIcon(buttonIcon);
        ui->item4->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 5:
        ui->item5->setText(n->getNoteID());
        ui->item5->setIcon(buttonIcon);
        ui->item5->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 6:
        ui->item6->setText(n->getNoteID());
        ui->item6->setIcon(buttonIcon);
        ui->item6->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 7:
        ui->item7->setText(n->getNoteID());
        ui->item7->setIcon(buttonIcon);
        ui->item7->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 8:
        ui->item8->setText(n->getNoteID());
        ui->item8->setIcon(buttonIcon);
        ui->item8->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 9:
        ui->item9->setText(n->getNoteID());
        ui->item9->setIcon(buttonIcon);
        ui->item9->setIconSize(p.rect().size());
        inventoryItemCounter++;
    }
}

void MainWindow::insertToGUI(keys *k) {
    QPixmap p(k->getimagePath());
    QIcon buttonIcon(p);

    switch (inventoryItemCounter) {
    case 1:
        ui->item1->setIcon(buttonIcon);
        ui->item1->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 2:
        ui->item2->setIcon(buttonIcon);
        ui->item2->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 3:
        ui->item3->setIcon(buttonIcon);
        ui->item3->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 4:
        ui->item4->setIcon(buttonIcon);
        ui->item4->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 5:
        ui->item5->setIcon(buttonIcon);
        ui->item5->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 6:
        ui->item6->setIcon(buttonIcon);
        ui->item6->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 7:
        ui->item7->setIcon(buttonIcon);
        ui->item7->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 8:
        ui->item8->setIcon(buttonIcon);
        ui->item8->setIconSize(p.rect().size());
        inventoryItemCounter++;
        break;
    case 9:
        ui->item9->setIcon(buttonIcon);
        ui->item9->setIconSize(p.rect().size());
        inventoryItemCounter++;
    }
}

void MainWindow::displayLastRiddle() {
    lastRiddle = new LastRiddle(NULL, &answer);
    lastRiddle->setModal(true);
    lastRiddle->exec();

    if(zork->checkAnswer(answer)) {
        gameEnd = new GameEnd();
        gameEnd->setModal(true);
        gameEnd->exec();

        this->close();
    }

}

void MainWindow::on_UseItem_clicked()
{
    gameEnd = new GameEnd();
    gameEnd->setModal(true);
    gameEnd->exec();

    this->close();
}

void MainWindow::on_item1_clicked()
{
    if(inventoryItems.size()>0)
    {
     Item *check  = inventoryItems.at(0);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note = (notes *) inventoryItems.at(0);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->document()->setHtml(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(0);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,0);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
 /*   if(ui->item1->text() != NULL) {
        notes *note = zork->findNote(ui->item1->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item2_clicked()
{

    if(inventoryItems.size()>1)
    {
     Item *check  = inventoryItems.at(1);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note = (notes *) inventoryItems.at(1);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->document()->setHtml(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(1);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,1);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }

   /* if(ui->item2->text() != NULL) {

    } */
}

void MainWindow::on_item3_clicked()
{
    if(inventoryItems.size()>2)
    {
     Item *check  = inventoryItems.at(2);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note = (notes *) inventoryItems.at(2); //zork->findNote(ui->item2->text());
        ui->roomInfoOutput->document()->setHtml(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(2);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,2);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
 /*   if(ui->item3->text() != NULL) {
        notes *note = zork->findNote(ui->item3->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item4_clicked()
{
    if(inventoryItems.size()>3)
    {
     Item *check  = inventoryItems.at(3);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note =  (notes *) inventoryItems.at(3);// zork->findNote(ui->item2->text());
        ui->roomInfoOutput->document()->setHtml(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(3);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,3);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /* if(ui->item4->text() != NULL) {
        notes *note = zork->findNote(ui->item4->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item5_clicked()
{
    if(inventoryItems.size()>4)
    {
     Item *check  = inventoryItems.at(4);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note =  (notes *) inventoryItems.at(4);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->document()->setHtml(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(4);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,4);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /*  if(ui->item5->text() != NULL) {
        notes *note = zork->findNote(ui->item5->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item6_clicked()
{
    if(inventoryItems.size()>5)
    {
     Item *check  = inventoryItems.at(5);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note =  (notes *) inventoryItems.at(5);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->setPlainText(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(5);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,5);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /* if(ui->item6->text() != NULL) {
        notes *note = zork->findNote(ui->item6->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item7_clicked()
{
    if(inventoryItems.size()>6)
    {
     Item *check  = inventoryItems.at(6);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note =  (notes *) inventoryItems.at(6);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->setPlainText(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(6);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,6);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /*if(ui->item7->text() != NULL) {
        notes *note = zork->findNote(ui->item7->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item8_clicked()
{
    if(inventoryItems.size()>7)
    {
     Item *check  = inventoryItems.at(7);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note =  (notes *) inventoryItems.at(7);//zork->findNote(ui->item2->text());
        ui->roomInfoOutput->setPlainText(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(7);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,7);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /*if(ui->item8->text() != NULL) {
        notes *note = zork->findNote(ui->item8->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}

void MainWindow::on_item9_clicked()
{
    if(inventoryItems.size()>8)
    {
     Item *check  = inventoryItems.at(8);
     if(check->getShortDescription().compare("NOTE") == 0) {
        notes *note = (notes *) inventoryItems.at(8); //zork->findNote(ui->item2->text());
        ui->roomInfoOutput->setPlainText(note->getContents());

      }
     else if(check->getShortDescription().compare("KEY") == 0) {
         keys *key = (keys *) inventoryItems.at(8);
         Room *cur = zork->getCurrentRoom();
         vector<Room*> curExits = cur->getExits();
         bool unlocked = false;
         for(int i = 0; i < curExits.size(); i++)
         {
            unlocked = curExits.at(i)->checkUnlockDoor(key);
            if(unlocked)
            {
                ui->roomInfoOutput->setPlainText("Key used on " + curExits.at(i)->shortDescription() + " door.");
                QString curRoom = cur->shortDescription();
                on_unlocked_Door(curRoom,8);
                break;
            }
         }
         if(!unlocked)
         {
           ui->roomInfoOutput->setPlainText("Key does not match any door");
         }

     }
     else {
             ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
     }
    }
    else {
            ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }
    /*  if(ui->item9->text() != NULL) {
        notes *note = zork->findNote(ui->item9->text());
        ui->roomInfoOutput->setPlainText(note->getContents());
    } else {
        ui->roomInfoOutput->setPlainText("There is nothing to view on this item");
    }*/
}
