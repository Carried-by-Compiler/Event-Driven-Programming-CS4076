#ifndef ROOM_H_
#define ROOM_H_

#include <QString>
#include <QPixmap>
#include <string>
#include <map>
#include <vector>
#include "item.h"
#include "notes.h"

using namespace std;
using std::vector;

class Room {

private:
    QString description;
    QString viewPath;
    QString keyID;
    vector<Room*> exits;
    QString exitString();
    vector<Item*> itemsInRoom;
    QPixmap roomInMapImage;
    bool upstairs;
    bool downstairs;
    bool locked;

public:
    Room(QString = "", QString = "", QString = "", bool = false, bool = false, bool = false, QString = "");
    void setExits(vector<Room*>&);
    void addNote(notes*);
    vector<Room*> getExits();
    vector<Item*> getItems();
    QString shortDescription();
    QString longDescription();
    bool canGoUp();
    bool canGoDown();
    bool checkIfLocked();
    QPixmap getPixmap();
    QString getViewPixmap();
    QString getNotepath();
};

#endif
