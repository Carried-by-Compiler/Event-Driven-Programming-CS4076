#include "notes.h"
#include <iostream>

notes::notes(QString label, QString contents, QString imagePath) :  Item(label)
{
    this->noteID = noteID;
    this->contents = contents;
    this->imagePath = imagePath;
}


notes::~notes() {

    std::cout << "Deleting note " << noteID.toStdString() << endl;
}

void notes::setNoteID(QString id) {
    this->noteID = id;
}

QString notes::getNoteID() { return this->noteID; }

QString notes::getContents(){
    return contents;
}

QString notes::getimagePath(){
    return imagePath;
}

