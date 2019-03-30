#include "Room.h"


Room::Room(string description, string type) {
	this->description = description;
    this->type = type;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != nullptr)
		exits["north"] = north;
    if (east != nullptr)
		exits["east"] = east;
    if (south != nullptr)
		exits["south"] = south;
    if (west != nullptr)
		exits["west"] = west;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
    return "\nroom = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
        return nullptr; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}


void Room::addItem(Item *inItem) {
    //cout <<endl;
    //cout << "Just added" + inItem->getLongDescription();
    itemsInRoom.push_back(inItem);
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x]->getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfItems() {
    return itemsInRoom.size();
}

void Room::removeItemFromRoom(string inString)
{
    int sizeItems = (static_cast<int>(this->itemsInRoom.size())); //TODO fix
    if (static_cast<int>(this->itemsInRoom.size() > 0)) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x]->getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
            }
            x++;
        }
    }
}

Item* Room::getItemFromString(string itemDesc){
    Item *returnItem;
    int sizeItems = (static_cast<int>(this->itemsInRoom.size()));
    if (static_cast<int>(this->itemsInRoom.size() > 0)) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = itemDesc.compare( (*itemsInRoom[x]).getShortDescription());
            if (tempFlag == 0) {
                return (*(itemsInRoom.begin()+x));
            }
            x++;
        }
    }
}
