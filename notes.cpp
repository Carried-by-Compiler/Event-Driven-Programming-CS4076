#include "notes.h"

notes::notes(QString noteID, QString contents,QString imagePath)
{
    this->noteID = noteID;
    this->contents = contents;
    this->imagePath = imagePath;
}

QString notes::getContents(){
    return contents;
}

QString notes::getNoteID(){
    return noteID;
}

QString notes::getimagePath(){
    return imagePath;
}

