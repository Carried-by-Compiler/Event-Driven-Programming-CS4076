#ifndef FLOOR_H
#define FLOOR_H

#include <QString>
#include "Room.h"
#include <vector>
using std::vector;

class Floor {

private:
    QString floorMap;
    QString description;
    int floorNumber;
    vector<Room*> rooms;

    void initMap();

public:
    Floor();
    void setRooms(vector<Room*>&);
    void setDetails(int, QString);
    int  getFloorNum();
    QString getDesc();
    vector<Room*> getRooms();
};

#endif // FLOOR_H
