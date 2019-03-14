#include "zork.h"
#include "ui_zork.h"
#include "gameplay.h"

Zork::Zork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zork)
{
    ui->setupUi(this);

    gameplay play;
    play.createRooms();
    ui->outputText->append(play.printWelcome());
}

Zork::~Zork()
{
    delete ui;
}


void Zork::on_teleport_clicked()
{
    ui->outputText->append("Teleported");
    play.teleport();
    ui->outputText->append(QString::fromStdString(play.currentRoom->longDescription()));
}

void Zork::go(string direction) {
    ui->outputText->append(play.go(direction));
}

void Zork::on_goNorth_clicked()
{
    go("north");
}

void Zork::on_goEast_clicked()
{
    go("east");
}

void Zork::on_goSouth_clicked()
{
    go("south");
}

void Zork::on_goWest_clicked()
{
    go("west");
}

void Zork::on_map_clicked()
{
    ui->outputText->append(play.map());
}






/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool Zork::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();

    if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void Zork::printHelp() {
    cout << "\nvalid inputs are; " << endl;
    parser.showCommands();

}
