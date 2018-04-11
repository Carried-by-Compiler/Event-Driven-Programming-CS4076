#ifndef KEYS_H
#define KEYS_H
#include <QString>
#include "item.h"
class keys : public Item
{
private:
     QString keyID;
     QString imagePath;

public:
    keys(QString label, QString keyID = "",QString imagePath="");
    ~keys();
    QString getKeyID();
    QString getimagePath();
};

#endif //keys_h
