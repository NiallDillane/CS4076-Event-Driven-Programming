#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Item.h"

#include <string>
#include <sstream>
using namespace std;
#include <vector>
using std::vector;


class Character {
private:
	string description;
    vector <Item *> itemsInCharacter;

public:
    int health=50;
    void addItem(Item *item);
    void addItem(Item &item);

public:
    Character();
	Character(string description);
	string shortDescription();
	string longDescription();
    string name;
    void setName(string name);
    string getName();
    string getHealth();
};

#endif
