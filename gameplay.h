#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <QMainWindow>
#include "Room.h"
using std::string;

class gameplay
{
public:
    gameplay();
    Room *currentRoom;
    void createRooms();
    vector<Room*> rooms;
    QString printWelcome(string);
    void teleport();
    QString map();
    QString go(string direction);
private:
};

#endif // GAMEPLAY_H
