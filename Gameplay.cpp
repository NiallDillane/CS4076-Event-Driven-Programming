#include "Gameplay.h"

Gameplay::Gameplay()
{
    srand (time(0));
    createRooms();
}

QString Gameplay::printWelcome(string name) {
    string output =
           string("\nWelcome, ") + (name) + "!" +
           string("\n<-- Your health is on the left\n") +
           (this->currentRoom->longDescription());
    return QString::fromStdString(output);
}

void Gameplay::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a", "NA");
        a->addItem(new Food("Apple", 25));
        a->addItem(new Food("Spikes", -15));
    b = new Room("b", "NA");
        b->addItem(new Food("Bomb", -50));
        b->addItem(new Food("Banana", 40));
    c = new Room("c", "NA");
    d = new Room("d", "NA");
    e = new Room("e", "NA");
    f = new Room("f", "NA");
    g = new Room("g", "NA");
    h = new Room("h", "win");
    i = new Room("i", "NA");
    j = new Room("j", "NA");


    rooms.push_back(a); rooms.push_back(b); rooms.push_back(c); rooms.push_back(d); rooms.push_back(e);
    rooms.push_back(f); rooms.push_back(g); rooms.push_back(h); rooms.push_back(i); rooms.push_back(j);

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(nullptr, nullptr, nullptr, a);
    c->setExits(nullptr, a, nullptr, nullptr);
    d->setExits(a, e, nullptr, i);
    e->setExits(nullptr, nullptr, nullptr, d);
    f->setExits(j, g, a, h);
    g->setExits(nullptr, nullptr, nullptr, f);
    h->setExits(nullptr, f, nullptr, nullptr);
    i->setExits(nullptr, d, nullptr, nullptr);
    j->setExits(nullptr, nullptr, f, nullptr);

        currentRoom = a;
}

void Gameplay::teleport(){
    int randomIndex=0;
    do
        randomIndex = rand() % (this->rooms).size();
    while((*(this->currentRoom)).equals(*((this->rooms)[randomIndex])));
    this->currentRoom = (this->rooms)[randomIndex];
}

QString Gameplay::go(string direction) {
    Room* nextRoom = this->currentRoom->nextRoom(direction);
    string output;
    if (nextRoom == NULL)
        output = ("That's a dead-end!");
    else{
        output = ("Moving " + direction);
        this->currentRoom = nextRoom;
        output += "\n" + (this->currentRoom->longDescription());
    }
    return QString::fromStdString(output);
}

QString Gameplay::map(){
    string output =
        string  ("            [j]        ") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[h] --- [f] --- [g]") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[c] --- [a] --- [b]") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[i] --- [d] --- [e]");
    return QString::fromStdString(output);
}
