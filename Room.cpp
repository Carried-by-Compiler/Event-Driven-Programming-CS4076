#include "Room.h"
#include "item.h"
#include "keys.h"
#include "Command.h"

Room::Room(QString description, QString path, QString path2, bool up, bool down, bool locked, QString keyID) : roomInMapImage(path){
	this->description = description;
    this->upstairs = up;
    this->downstairs = down;
    this->viewPath = path2;
    this->locked = locked;
    this->keyID = keyID;
}
void Room::setExits(vector<Room*> &rooms) {
    this->exits = rooms;
}
bool Room::checkIfLocked(){
    return this->locked;
}
bool Room::checkUnlockDoor(keys *key){
    QString keyName = key->getKeyID();
    if(keyName.compare(keyID) == 0)
    {
        setLocked(false);
        return true;
    }
    else
    {
        return false;
    }
}
void Room::setLocked(bool lock){
     this->locked = lock;
}
QString Room::shortDescription() {
	return description;
}

QString Room::longDescription() {
    return "room = " + description + exitString();
}

vector<Item*> Room::getItems() { return this->itemsInRoom; }
vector<Room*> Room::getExits() { return this->exits; }

QString Room::exitString() {

    QString returnString = "\nExits:\n";
    for (int i = 0; i < exits.size(); i++) {
        returnString += "  " + exits.at(i)->shortDescription() + "\n";

    }

    return returnString;

}

void Room::addNote(notes *note) {
    this->itemsInRoom.push_back(note);
}
void Room::addKeys(keys *roomKey){
    this->itemsInRoom.push_back(roomKey);
}
void Room::clearRoomOfItems() { this->itemsInRoom.clear(); }
QString Room::getViewPixmap(){return this->viewPath;}
QPixmap Room::getPixmap()   { return this->roomInMapImage; }
bool Room::canGoUp()        { return this->upstairs;    }
bool Room::canGoDown()      { return this->downstairs;  }
