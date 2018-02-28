#include <iostream>

using namespace std;
#include "ZorkUL.h"
ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    //Can only access, and manipulate the variable rooms within this method, will leave behind memory but not access it.
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i,*j; // these are pointers to the object rooms.
    // all of the room pointers will only point to object rooms
    a = new Room("a"); // new puts the object on heap
        a->addItem(new Item("x"));
        a->addItem(new Item("y"));
	b = new Room("b");
        b->addItem(new Item("xx"));
        b->addItem(new Item("yy"));
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
	i = new Room("i");
    j = new Room("j");
// Only structures the exits in specific ways, not the location of the object rooms.
//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
	d->setExits(a, e, NULL, i);
	e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL,NULL,f,NULL);
 // current room is how to access these variables outside of this method, it holds only the
 //current position room and will tell ONLY what exits exist for the room you are in
        currentRoom = a;
      //  randRoom    = a;
        listOfRooms.push_back(a);
        listOfRooms.push_back(b);
        listOfRooms.push_back(c);
        listOfRooms.push_back(d);
        listOfRooms.push_back(e);
        listOfRooms.push_back(f);
        listOfRooms.push_back(j);
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
    else if(commandWord.compare("teleport")==0){
            goTeleport();
     }
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
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
}
Room* ZorkUL::getCurrentRoom(){
    return this->currentRoom;
}
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("direction null, please select a valid direction");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
string ZorkUL::getMap(){
    string mapString = " \t[j] \t \n \t | \t \n [h] --- [f] --- [g] \n \t | \t \n \t | \t \n [c] --- [a] --- [b]\n\t | \t \n \t | \t \n [i] --- [d] --- [e]";
    return mapString;
}
