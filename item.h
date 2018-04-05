#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <QString>
#include <iostream>
using namespace std;

class Item {
private:
    QString description;
    QString longDescription;

public:
    Item (QString description);
    QString getShortDescription();
    QString getLongDescription();
};

#endif /*ITEM_H_*/
