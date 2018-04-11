#ifndef NOTES_H
#define NOTES_H
#include "item.h"
#include <QString>
#include <vector>

class notes : public Item {
private:
     QString noteID;
     QString contents;
     QString imagePath;

public:
    notes(QString = "", QString = "", QString = "",QString = "");
    ~notes();
    QString getNoteID();
    QString getContents();
    QString getimagePath();
    //vector<notes> *itemsInRoom;
    //vector<notes>* getNotesInRoom();
};

#endif // NOTES_H
