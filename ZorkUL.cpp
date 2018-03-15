#include <iostream>

using namespace std;
#include "ZorkUL.h"
ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    //Can only access, and manipulate the variable rooms within this method, will leave behind memory but not access it.
    Room *a, *b, *c, *d, *e; //*f, *g, *h, *i,*j; // these are pointers to the object rooms.
    vector<Room*> listOfRooms;
    Floor *f;

    // Basement
    a = new Room("Storage", true, false);
    b = new Room("Boiler Room", false, false);

    listOfRooms.push_back(b);
    a->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    b->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(b);

    f = new Floor();
    f->setRooms(listOfRooms);
    f->setDetails(0, "Basement");
    floorList.push_back(f);

    listOfRooms.clear();

    // First Floor
    a = new Room("Hallway", true, true);
    b = new Room("Kitchen");
    c = new Room("Toilet");
    d = new Room("Dining Room");
    e = new Room("Living Room");
    listOfRooms.push_back(b);
    listOfRooms.push_back(c);
    listOfRooms.push_back(d);
    listOfRooms.push_back(e);
    a->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(d);
    b->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    c->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(b);
    d->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    e->setExits(listOfRooms);
    listOfRooms.clear();

    currentRoom = a;

    listOfRooms.push_back(a);
    listOfRooms.push_back(b);
    listOfRooms.push_back(c);
    listOfRooms.push_back(d);
    listOfRooms.push_back(e);

    f = new Floor();
    f->setRooms(listOfRooms);
    f->setDetails(1, "Main Floor");
    floorList.push_back(f);

    listOfRooms.clear();

    currentFloor = floorList.at(1);

    // Top Floor
    a = new Room("Hallway", false, true);
    b = new Room("Son's Room");
    c = new Room("Bathroom");
    d = new Room("Daughter's Room");
    e = new Room("Parent's Room");

    listOfRooms.push_back(b);
    listOfRooms.push_back(c);
    listOfRooms.push_back(d);
    listOfRooms.push_back(e);
    a->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    b->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(e);
    c->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    d->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(c);
    e->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(b);
    listOfRooms.push_back(c);
    listOfRooms.push_back(d);
    listOfRooms.push_back(e);

    f = new Floor();
    f->setRooms(listOfRooms);
    f->setDetails(2, "Top Floor");
    floorList.push_back(f);

    listOfRooms.clear();

}

Room* ZorkUL::getCurrentRoom(){
    return this->currentRoom;
}

Floor* ZorkUL::getCurrentFloor() {
    return this->currentFloor;
}

bool ZorkUL::canGoUpstairs() {
    return currentRoom->canGoUp();
}

void ZorkUL::moveFloorUp() {
    currentFloor = floorList.at(currentFloor->getFloorNum() + 1);
    currentRoom = currentFloor->getRooms().at(0);
}

bool ZorkUL::canGoDownstairs() {
    return currentRoom->canGoDown();
}

void ZorkUL::moveFloorDown() {
    currentFloor = floorList.at(currentFloor->getFloorNum() - 1);
    currentRoom = currentFloor->getRooms().at(0);
}

void ZorkUL::go(QString selectedExit) {

    vector<Room*> rooms = currentFloor->getRooms();
    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i)->shortDescription().compare(selectedExit)) == 0) {
            currentRoom = rooms.at(i);
            break;
        }
    }
}
