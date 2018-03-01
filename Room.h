#ifndef ROOM_H_
#define ROOM_H_

#include <QString>
#include <string>
#include <map>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    QString description;
    //map<string, Room*> exits;
    vector<Room*> exits;
    QString exitString();
    vector <Item> itemsInRoom;
    bool upstairs;
    bool downstairs;


public:
    int numberOfItems();
    Room(QString);
    Room(QString, bool, bool);
    //void setExits(Room *north, Room *east, Room *south, Room *west);
    void addExit(Room*);
    vector<Room*> getExits();
    QString shortDescription();
    QString longDescription();
    Room* nextRoom(string direction);
    bool canGoUp();
    bool canGoDown();
    //void addItem(Item *inItem);
    //QString displayItem();
    //int isItemInRoom(string inString);
    //void removeItemFromRoom(int location);
};

#endif
