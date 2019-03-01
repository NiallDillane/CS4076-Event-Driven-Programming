#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

class ZorkUL {
private:
	Parser parser;
	Room *currentRoom;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void tp();
    void createItems();
    void displayItems();
    vector<Room*> rooms;

public:
	ZorkUL();
	void play();
	string go(string direction);
};

#endif /*ZORKUL_H_*/
