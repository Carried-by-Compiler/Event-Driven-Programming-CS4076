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
    a = new Room("Storage", ":/maps/basement_storage.png", true, false);
    b = new Room("Boiler Room", ":/maps/basement_boiler.png", false, false);

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
    a = new Room("Hallway", ":/maps/ground_hallway.png", true, true);
    b = new Room("Kitchen", ":/maps/ground_kitchen.png");
    c = new Room("Toilet", ":/maps/ground_toilet.png");
    d = new Room("Dining Room", ":/maps/ground_dining.png");
    e = new Room("Living Room", ":/maps/ground_living.png");
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
    listOfRooms.push_back(c);
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
    a = new Room("Hallway", ":/maps/top_hallway.png", false, true);
    b = new Room("Son's Room", ":/maps/top_s_room.png");
    c = new Room("Bathroom", ":/maps/top_bathroom.png");
    d = new Room("Daughter's Room", ":/maps/top_d_room.png");
    e = new Room("Parent's Room", ":/maps/top_p_room.png");

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

QPixmap ZorkUL::moveFloorUp() {
    currentFloor = floorList.at(currentFloor->getFloorNum() + 1);
    currentRoom = currentFloor->getRooms().at(0);
    return currentRoom->getPixmap();
}

bool ZorkUL::canGoDownstairs() {
    return currentRoom->canGoDown();
}

QPixmap ZorkUL::moveFloorDown() {
    currentFloor = floorList.at(currentFloor->getFloorNum() - 1);
    currentRoom = currentFloor->getRooms().at(0);
    return currentRoom->getPixmap();
}

QPixmap ZorkUL::go(QString selectedExit) {

    vector<Room*> rooms = currentFloor->getRooms();
    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i)->shortDescription().compare(selectedExit)) == 0) {
            currentRoom = rooms.at(i);
            break;
        }
    }
    return currentRoom->getPixmap();
}
