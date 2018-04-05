#include "notes.h"

notes::notes(QString label, QString noteID, QString contents,QString imagePath) :  Item(label)
{
    this->noteID = noteID;
    this->contents = contents;
    this->imagePath = imagePath;
}

QString notes::getContents(){
    return contents;
}

QString notes::getimagePath(){
    return imagePath;
}

