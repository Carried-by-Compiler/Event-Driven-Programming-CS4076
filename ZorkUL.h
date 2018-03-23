#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "floor.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <time.h>
using namespace std;

class ZorkUL {
private:
    //vector<Room*> listOfRooms;
    //vector<Room*>::iterator it = listOfRooms.begin();
    vector<Floor*> floorList;
    Floor *currentFloor;
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
    Floor* getCurrentFloor();
    bool canGoUpstairs();
    bool canGoDownstairs();
    void moveFloorUp();
    void moveFloorDown();
	ZorkUL();
	void play();
    void goTeleport();
    string getWelcome();
    string getMap();
    QPixmap go(QString);
};

#endif /*ZORKUL_H_*/
