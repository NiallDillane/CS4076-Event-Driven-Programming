#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <QMainWindow>
#include "Room.h"
#include "Item.h"
#include "Food.h"
using std::string;

class Gameplay
{
private:
    Gameplay();
    Room *currentRoom;
    void createRooms();
    vector<Room*> rooms;
    QString printWelcome(string);
    void teleport();
    QString map();
    QString go(string direction);
public:
    friend class Zork;
};

#endif // GAMEPLAY_H
