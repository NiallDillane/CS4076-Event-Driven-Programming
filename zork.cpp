#include "zork.h"
#include "ui_zork.h"
#include "ZorkUL.h"

Zork::Zork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zork)
{
    ui->setupUi(this);

    srand(time(0));
    createRooms();
    printWelcome();

}

Zork::~Zork()
{
    delete ui;
}

void Zork::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
        a->addItem(new Item("x", 1, 11));
        a->addItem(new Item("y", 2, 22));
    b = new Room("b");
        b->addItem(new Item("xx", 3, 33));
        b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");
    j = new Room("j");


    rooms.push_back(a); rooms.push_back(b); rooms.push_back(c); rooms.push_back(d); rooms.push_back(e);
    rooms.push_back(f); rooms.push_back(g); rooms.push_back(h); rooms.push_back(i); rooms.push_back(j);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(j, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL, NULL, f, NULL);

        currentRoom = a;
}

void Zork::printWelcome() {
    ui->outputText->append("\n--START--");
    ui->outputText->append("info for help");
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));

}

void Zork::on_teleport_clicked()
{
    ui->outputText->append("Teleported");
    int randomIndex=0;
    do
        randomIndex = rand() % rooms.size();
    while(currentRoom==rooms[randomIndex]);
    currentRoom = rooms[randomIndex];
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));
}

void Zork::on_goNorth_clicked()
{
    ui->outputText->append("Moved North");
    Room* nextRoom = currentRoom->nextRoom("north");
    currentRoom = nextRoom;
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));
}


void Zork::on_goEast_clicked()
{
    ui->outputText->append("Moved East");
    Room* nextRoom = currentRoom->nextRoom("east");
    currentRoom = nextRoom;
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));
}

void Zork::on_goSouth_clicked()
{
    ui->outputText->append("Moved South");
    Room* nextRoom = currentRoom->nextRoom("south");
    currentRoom = nextRoom;
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));
}

void Zork::on_goWest_clicked()
{
    ui->outputText->append("Moved West");
    Room* nextRoom = currentRoom->nextRoom("west");
    currentRoom = nextRoom;
    ui->outputText->append(QString::fromStdString(currentRoom->longDescription()));
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
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "        [j]        " << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
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

    else if (commandWord.compare("tp") == 0)
    {

        int randomIndex=0;
        do
            randomIndex = rand() % rooms.size();
        while(currentRoom==rooms[randomIndex]);
        currentRoom = rooms[randomIndex];
        cout << currentRoom->longDescription() << endl;
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

void Zork::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

string Zork::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

