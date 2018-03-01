#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <list>
#include <time.h>
using namespace std;

class ZorkUL {
private:
    list<Room*> listOfRooms;
    list<Room*>::iterator it = listOfRooms.begin();
	Room *currentRoom;
    Room *randRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    Room* rndRoom();
   // void goTeleport();

public:
    Room* getCurrentRoom();
	ZorkUL();
	void play();
    void goTeleport();
    string getWelcome();
    string getMap();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
