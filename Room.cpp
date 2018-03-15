#include "Room.h"
#include "Command.h"

Room::Room(QString description) {
    this->description = description;
    this->upstairs = false;
    this->downstairs = false;
}

Room::Room(QString description, bool up, bool down) {
	this->description = description;
    this->upstairs = up;
    this->downstairs = down;
}

void Room::addExit(Room *anotherRoom) {
    exits.push_back(anotherRoom);
}

QString Room::shortDescription() {
	return description;
}

QString Room::longDescription() {
    return "room = " + description + exitString();
}

vector<Room*> Room::getExits() { return this->exits; }

QString Room::exitString() {

    QString returnString = "\nExits:\n";
    for (int i = 0; i < exits.size(); i++) {
        returnString += "  " + exits.at(i)->shortDescription() + "\n";

    }
    return returnString;

}

bool Room::canGoUp()    { return this->upstairs;    }
bool Room::canGoDown()  { return this->downstairs;  }

