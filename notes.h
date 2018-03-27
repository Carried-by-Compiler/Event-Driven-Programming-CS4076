#ifndef NOTES_H
#define NOTES_H
#include <QString>
#include <vector>

class notes
{
private:
     QString noteID;
     QString contents;
     QString imagePath;

public:
    notes(QString noteID = "", QString contents = "",QString imagePath="");
    QString getNoteID();
    QString getContents();
    QString getimagePath();
    //vector<notes> *itemsInRoom;
    //vector<notes>* getNotesInRoom();
};

#endif // NOTES_H
