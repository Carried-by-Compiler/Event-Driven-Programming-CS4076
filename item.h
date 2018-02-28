#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
	string description;
	string longDescription;

public:
    Item (string description);
	string getShortDescription();
    string getLongDescription();
};

#endif /*ITEM_H_*/
