#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "floor.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "notes.h"
#include "keys.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <time.h>
using namespace std;

class ZorkUL {

    //friend QString &operator +(const QString &, int);

private:
    //vector<Room*> listOfRooms;
    //vector<Room*>::iterator it = listOfRooms.begin();
    vector<Floor*> floorList;
    vector<notes*> notesList;
    vector<keys*> keyList;
    Floor *currentFloor;
    Room *currentRoom;
    Room *randRoom;
    QString answer;
    //notes *currentNote;
 //   vector<notes*> listOfNotes;
    void initializeGame();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();
    //void createNotes();
   // void goTeleport();

public:
    ~ZorkUL();
    ZorkUL();
    Room* getCurrentRoom();
    Floor* getCurrentFloor();
    //notes* getCurrentNote();
    bool canGoUpstairs();
    bool canGoDownstairs();
    QPixmap moveFloorUp();
    QPixmap moveFloorDown();
	void play();
    void goTeleport();
    string getWelcome();
    string getMap();
    void addKeys(keys*);
    QPixmap go(QString);
    notes* findNote(QString);
    void addNote(notes*);
    bool checkAnswer(QString);
};

#endif /*ZORKUL_H_*/
