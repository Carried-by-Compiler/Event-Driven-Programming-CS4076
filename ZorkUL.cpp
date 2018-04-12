#include <iostream>

using namespace std;
#include "ZorkUL.h"
ZorkUL::ZorkUL() {
    initializeGame();
}

ZorkUL::~ZorkUL() {
    std::cout << "Deleting ZorkUL" << endl;

    for(int i = 0; i < floorList.size(); i++)
        delete floorList.at(i);
    for(int i = 0; i < keyList.size(); i++)
        delete keyList.at(i);
    for(int i = 0; i < notesList.size(); i++)
        delete notesList.at(i);


}

void ZorkUL::initializeGame()  {
    this->answer = "SILENCE";
    
    QString message = "";
    Room *a, *b, *c, *d, *e ,*FrontDoor; //*f, *g, *h, *i,*j; // these are pointers to the object rooms.
    vector<Room*> listOfRooms;
    Floor *f;

    // Basement
    a = new Room("Basement", ":/maps/basement_storage.png",":/roomView/basement_view.jpg", true, false);
    b = new Room("Boiler Room", ":/maps/basement_boiler.png",":/roomView/boilerRoom_view.jpg",false, false, true, "BoilerKey");

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
    a = new Room("Hallway", ":/maps/ground_hallway.png",":/roomView/hallway1_view.jpg", true, true);
    b = new Room("Kitchen", ":/maps/ground_kitchen.png",":/roomView/Kitchen_view.jpg",false,false,false,"null");
    c = new Room("Toilet", ":/maps/ground_toilet.png",":/roomView/Bathroom1_view.jpg",false,false,false,"null");
    d = new Room("Dining Room", ":/maps/ground_dining.png",":/roomView/diningRoom_view.jpg",false,false,true,"DiningKey");
    e = new Room("Living Room", ":/maps/ground_living.png",":/roomView/livingRoom_view.jpg",false,false,false,"null");
    FrontDoor = new Room("Front Door","","", false, false, true, "FrontKey");

    listOfRooms.push_back(b);
    listOfRooms.push_back(c);
    listOfRooms.push_back(d);
    listOfRooms.push_back(e);
    listOfRooms.push_back(FrontDoor);
    a->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(d);
    b->setExits(listOfRooms);
    listOfRooms.clear();

    listOfRooms.push_back(a);
    listOfRooms.push_back(e);
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
    a = new Room("Hallway", ":/maps/top_hallway.png", ":/roomView/hallway_view.jpg",false, true);
    b = new Room("Son's Room", ":/maps/top_s_room.png",":/roomView/Bedroom1_view.jpg");
    c = new Room("Bathroom", ":/maps/top_bathroom.png", ":/roomView/Bathroom2_view.jpg",false,false,true,"BathKey");
    d = new Room("Daughter's Room", ":/maps/top_d_room.png",":/roomView/Bedroom3_view.jpg");
    e = new Room("Parent's Room", ":/maps/top_p_room.png",":/roomView/Bedroom2_view.jpg",false,false, true, "ParentsKey");
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
    
    placeItemsInRooms();

} 

ostream &operator<<(ostream &o, const QString &s) {

    o << s.toStdString();

    return o;
}

void ZorkUL::placeItemsInRooms() {

    QString message = "";
    Item *selectedItem = 0;
    vector<Item*> listOfItems; 
    vector<Room*> rooms;
    Room *selectedRoom = 0;
    int floorIndex, roomIndex, itemIndex;
    
    message = "<html><b>L</b>ove of mon<b>E</b>y is a root of all sorts of injurious things.</html>";
    listOfItems.push_back(new notes("NOTE", message, ":/items/Page_image.png"));
    message = "<html><b>S</b>ometimes it's a good <b>I</b>dea to give up.</html>";
    listOfItems.push_back(new notes("NOTE", message,":/items/Page_image.png"));
    message = "Throw me out of the window you'll leave a grieving wife but bring me in through the door you'll see someone giving life. What am I?";
    listOfItems.push_back(new notes("NOTE", message, ":/items/Page_image.png"));
    message = "<html>It is our <b>C</b>hoices, that show what w<b>E</b> truly are, far more than our abilities.</html>";
    listOfItems.push_back(new notes("NOTE", message, ":/items/Page_image.png"));
    
    listOfItems.push_back(new keys("KEY", "BoilerKey", ":/items/Key_image.png"));
    listOfItems.push_back(new keys("KEY", "FrontKey", ":/items/Key_image.png"));
    listOfItems.push_back(new keys("KEY", "ParentsKey",":/items/Key_image.png" ));
    listOfItems.push_back(new keys("KEY", "DiningKey",":/items/Key_image.png"));
    listOfItems.push_back(new keys("KEY", "BathKey",":/items/Key_image.png"));
    
    while(listOfItems.size() != 0) {
        
        floorIndex = rand() % floorList.size();
        rooms = floorList.at(floorIndex)->getRooms();
        cout << "Floor index:\t" << floorIndex << endl;
        
        roomIndex = rand() % rooms.size();
        selectedRoom = rooms.at(roomIndex);
        cout << "selected room:\t" << selectedRoom->shortDescription() << endl;
        
        itemIndex = rand() % listOfItems.size();
        selectedItem = listOfItems.at(itemIndex);
        cout << "item index:\t\t" << itemIndex << endl;

        
        if(selectedItem->getShortDescription().compare("NOTE") == 0) {
            cout << "selectedItem:\t " << selectedItem->getShortDescription() << endl << endl;
            notes *n = (notes*)selectedItem;
            n->setNoteID(selectedRoom->shortDescription());
            selectedRoom->addNote(n);
            listOfItems.erase(listOfItems.begin() + itemIndex);
        } else if (selectedItem->getShortDescription().compare("KEY") == 0) {
            cout << "selectedItem:\t " << selectedItem->getShortDescription() << endl;
            keys *k = (keys*)selectedItem;
            selectedRoom->addKeys(k);
            cout << "room key unlocks:\t" << k->getKeyID() << endl << endl;
            if(*k != *selectedRoom)
                listOfItems.erase(listOfItems.begin() + itemIndex);
        }

    }
}


notes* ZorkUL::findNote(QString nID) {
    notes *n = 0;
    for(int i = 0; i < notesList.size(); i++) {
        if(notesList.at(i)->getNoteID().compare(nID) == 0) {
            n = notesList.at(i);
            break;
        }
    }
    return n;
}

void ZorkUL::addNote(notes *note) {
    notesList.push_back(note);
}
void ZorkUL::addKeys(keys *key) {
    keyList.push_back(key);
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
            bool check = rooms.at(i)->checkIfLocked();
            if(!check){
            currentRoom = rooms.at(i);
            }
            else{

            }
            break;
        }
    }
    return currentRoom->getPixmap();
}

bool ZorkUL::checkAnswer(QString input) {
    bool correct = false;
    QString capital = input.toUpper();

    if(capital.compare(this->answer) == 0)
        correct = true;

    return correct;

}
