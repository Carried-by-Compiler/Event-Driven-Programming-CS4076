#include "item.h"
#include <iostream>

Item::Item (QString inDescription) {
	description = inDescription;
}

Item::~Item() {
    cout << "Deleting item " << this->description.toStdString() << endl;

}

QString Item::getShortDescription()
{
	return description;
}

QString Item::getLongDescription()
{
    return "This is a " + this->description + ".\n";
}

