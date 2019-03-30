#ifndef ZORK_H
#define ZORK_H

#include <QMainWindow>
#include <QCommandLinkButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressBar>
#include <QPushButton>
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Gameplay.h"
#include "Character.h"
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
    Gameplay game;
    Character player;
private slots:
    void on_teleport_clicked();
    void on_goNorth_clicked();
    void on_goEast_clicked();
    void on_goSouth_clicked();
    void on_goWest_clicked();
    void on_map_clicked();
    void on_TakeX_clicked();
    void on_inventory_clicked();
    void on_TakeY_clicked();
    void on_TakeZ_clicked();

private:
    Ui::Zork *ui;
    Room *currentRoom;
    void createRooms();
    vector<Room*> rooms;
    void takeButtons();
    void printWelcome();
    void printHelp();
    void tp();
    void createItems();
    void displayItems();
    void healthChange(int delta);
    void gameWon(string desc);
    void gameLost(string desc);
    void takeItem(QPushButton* takeBtn);
    void gameOver(string title, string body, string desc);
    void checkWin();
};

#endif // ZORK_H
