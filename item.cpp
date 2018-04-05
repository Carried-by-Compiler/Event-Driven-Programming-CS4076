#include "item.h"

Item::Item (QString inDescription) {
	description = inDescription;
}
QString Item::getShortDescription()
{
	return description;
}

QString Item::getLongDescription()
{
    return "This is a " + this->description + ".\n";
}

