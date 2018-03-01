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
    // all of the room pointers will only point to object rooms
    a = new Room("Storage", true, false);
    b = new Room("Boiler Room", false, false);

    a->addExit(b);
    b->addExit(a);

    listOfRooms.push_back(a);
    listOfRooms.push_back(b);

    f = new Floor();
    f->setRooms(listOfRooms);
    f->setDetails(0, "Basement");
    floorList.push_back(f);

    listOfRooms.clear();

    a = new Room("Hallway", true, true); // new puts the object on heap
        //a->addItem(new Item("x"));
       // a->addItem(new Item("y"));
    b = new Room("Kitchen");
       // b->addItem(new Item("xx"));
       // b->addItem(new Item("yy"));
    c = new Room("Toilet");
    d = new Room("Dining Room");
    e = new Room("Living Room");
    //f = new Room();
    //g = new Room();
    //h = new Room("h");
    //i = new Room("i");
    //j = new Room("j");
// Only structures the exits in specific ways, not the location of the object rooms.
//             (N, E, S, W)
    a->addExit(b);
    a->addExit(d);
    a->addExit(e);
    a->addExit(c);

    b->addExit(a);
    b->addExit(d);

    c->addExit(a);

    d->addExit(a);
    d->addExit(b);

    e->addExit(a);
    //f->setExits(j, g, a, h);
    //g->setExits(NULL, NULL, NULL, f);
    //h->setExits(NULL, f, NULL, NULL);
    //i->setExits(NULL, d, NULL, NULL);
    //j->setExits(NULL,NULL,f,NULL);
 // current room is how to access these variables outside of this method, it holds only the
 //current position room and will tell ONLY what exits exist for the room you are in
        currentRoom = a;
      //  randRoom    = a;
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

        a = new Room("Hallway", false, true);
        b = new Room("Son's Room");
        c = new Room("Bathroom");
        d = new Room("Daughter's Room");
        e = new Room("Parent's Room");

        a->addExit(b);
        a->addExit(c);
        a->addExit(d);
        a->addExit(e);

        b->addExit(a);

        c->addExit(a);
        c->addExit(e);

        d->addExit(a);

        e->addExit(a);
        e->addExit(c);

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

        //listOfRooms.push_back(f);
        //listOfRooms.push_back(j);
       // do randomiser to pick random item from list and set it to randRoom.

}

/**
 *  Main play routine.  Loops until end of play.
 */
/*void ZorkUL::play() {
    //this game works on a plain while loop.
	printWelcome();
    cout << endl;
    cout << "end" << endl;
}*/

string ZorkUL::getWelcome(){
    string welText = "start: info for help";
    return welText;
}
/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */


/*
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
        {

        cout << "        [j]        " << endl;
        cout << "         |         " << endl;
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

    else if (commandWord.compare("go") == 0){
		goRoom(command);
    }

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
/*
    else if(commandWord.compare("teleport")==0){
            goTeleport();
     }
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
//	}
/*
	return false;
}
/** COMMANDS **/
/*
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
//	parser.showCommands();

}
void ZorkUL::goTeleport(){
    Room* rroom = rndRoom();
    if(currentRoom == rroom){
        rroom = rndRoom();
    }
    else{
        currentRoom = rroom;
     //   cout << currentRoom->longDescription() << endl;
     }
}
void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}
        string direction = command.getSecondWord();

        // Try to leave current room.
        Room* nextRoom = currentRoom->nextRoom(direction);

        if (nextRoom == NULL)
            cout << "underdefined input"<< endl;
        else {
            currentRoom = nextRoom;
            cout << currentRoom->longDescription() << endl;
        }

}
Room* ZorkUL::rndRoom(){
    int genNum;
    srand(time(NULL));
    genNum = rand()% 10;
    //cout << genNum << endl;
    advance(it,genNum);
    randRoom = *it;
    it = listOfRooms.begin();
    return randRoom;
} */
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
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
    vector<Room*> rooms = currentFloor->getRooms();
    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i)->shortDescription().compare(selectedExit)) == 0) {
            currentRoom = rooms.at(i);
            break;
        }
    }
    /*
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("direction null, please select a valid direction");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
    } */
}



/*
string ZorkUL::getMap(){
    string mapString = " \t[j] \t \n \t | \t \n [h] --- [f] --- [g] \n \t | \t \n \t | \t \n [c] --- [a] --- [b]\n\t | \t \n \t | \t \n [i] --- [d] --- [e]";
    return mapString;
} */
