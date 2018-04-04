#include "keys.h"

keys::keys(QString keyID,QString imagePath)
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

