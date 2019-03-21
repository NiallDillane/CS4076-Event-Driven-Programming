#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <QMainWindow>
#include "item.h"
using namespace std;
using std::vector;

class Room {

private:
    string description;
	map<string, Room*> exits;
    string exitString();


public:
    int numberOfItems();
    string type;
    Room(string description, string type);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
    string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    void removeItemFromRoom(string inString);
    vector <Item> itemsInRoom;
    Item getItemFromString(string itemDesc);
};

#endif
