#include "keys.h"
#include <iostream>

keys::keys(QString label, QString keyID, QString imagePath) : Item(label)
{
     this->keyID = keyID;
     this->imagePath=imagePath;
}

keys::~keys() {
    std::cout << "Deleting keys " << this->keyID.toStdString() << endl;
}

QString keys::getKeyID(){
    return this->keyID;
}

QString keys::getimagePath(){
    return this->imagePath;
}
