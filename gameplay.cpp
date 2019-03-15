#include "gameplay.h"

gameplay::gameplay()
{
    srand (time(0));
    createRooms();
}

QString gameplay::printWelcome(string name) {
    string output =
           string("\nWelcome, ") + (name) +
           string("\ninfo for help") +
           (this->currentRoom->longDescription());
    return QString::fromStdString(output);
}

void gameplay::createRooms()  {
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

void gameplay::teleport(){
    int randomIndex=0;
    do
        randomIndex = rand() % (this->rooms).size();
    while(this->currentRoom==(this->rooms)[randomIndex]);
    this->currentRoom = (this->rooms)[randomIndex];
}

QString gameplay::go(string direction) {
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

QString gameplay::map(){
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
