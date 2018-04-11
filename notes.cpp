#include "notes.h"
#include <iostream>

notes::notes(QString label, QString noteID, QString contents,QString imagePath) :  Item(label)
{
    this->noteID = noteID;
    this->contents = contents;
    this->imagePath = imagePath;
}


notes::~notes() {

    std::cout << "Deleting note " << noteID.toStdString();
}

QString notes::getNoteID() { return this->noteID; }

QString notes::getContents(){
    return contents;
}

QString notes::getimagePath(){
    return imagePath;
}

