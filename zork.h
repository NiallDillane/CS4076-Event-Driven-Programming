#ifndef ZORK_H
#define ZORK_H

#include <QMainWindow>
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "gameplay.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::vector;

namespace Ui {
class Zork;
}

class Zork : public QMainWindow
{
    Q_OBJECT

public:
    explicit Zork(QWidget *parent = nullptr);
    ~Zork();
    void go(string direction);
    gameplay game;
    Character player;

private slots:
    void on_teleport_clicked();

    void on_goNorth_clicked();

    void on_goEast_clicked();

    void on_goSouth_clicked();

    void on_goWest_clicked();

    void on_map_clicked();


    void on_healthBar_valueChanged(int value);

    void on_TakeX_clicked();

private:
    Ui::Zork *ui;
    Parser parser;
    Room *currentRoom;
    void createRooms();
    vector<Room*> rooms;
    void takeButtons();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void tp();
    void createItems();
    void displayItems();

};

#endif // ZORK_H
