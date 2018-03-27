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
    vector<Room*> exits;
    QString exitString();
    vector <Item> itemsInRoom;
    QPixmap roomInMapImage;
    bool upstairs;
    bool downstairs;
public:
     Room(QString = "", QString = "", QString = "", bool = false, bool = false);
    void setExits(vector<Room*>&);
    vector<Room*> getExits();
    QString shortDescription();
    QString longDescription();
    bool canGoUp();
    bool canGoDown();
    QPixmap getPixmap();
    QString getViewPixmap();
    QString getNotepath();
};

#endif
