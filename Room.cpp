#include "Room.h"
#include "item.h"
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

QString Room::getViewPixmap(){return this->viewPath;}
QPixmap Room::getPixmap()   { return this->roomInMapImage; }
bool Room::canGoUp()        { return this->upstairs;    }
bool Room::canGoDown()      { return this->downstairs;  }

