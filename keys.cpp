#include "keys.h"

keys::keys(QString label, QString keyID,QString imagePath) : Item(label)
{
     this->keyID = keyID;
     this->imagePath=imagePath;
}

QString keys::getKeyID(){
    return keyID;
}

QString keys::getimagePath(){
    return imagePath;
}

