#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "floor.h"
#include "Room.h"
#include "item.h"
#include "notes.h"
#include "keys.h"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <string>
#include <list>
#include <vector>
using namespace std;

class ZorkUL {

    friend ostream &operator<<(ostream &, const QString &);

private:
    vector<Floor*> floorList;
    vector<notes*> notesList;
    vector<keys*> keyList;
    Floor *currentFloor;
    Room *currentRoom;
    Room *randRoom;
    QString answer;



    void initializeGame();
    void createItems();
    void displayItems();

public:
    ~ZorkUL();
    ZorkUL();
    Room* getCurrentRoom();
    Floor* getCurrentFloor();
    bool canGoUpstairs();
    bool canGoDownstairs();
    QPixmap moveFloorUp();
    QPixmap moveFloorDown();
	void play();
    void goTeleport();
    void addKeys(keys*);
    void placeItemsInRooms();
    QPixmap go(QString);
    notes* findNote(QString);
    void addNote(notes*);
    bool checkAnswer(QString);
};

#endif /*ZORKUL_H_*/
