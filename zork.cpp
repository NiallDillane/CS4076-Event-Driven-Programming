#include "zork.h"
#include "ui_zork.h"
#include "gameplay.h"

#include <QCommandLinkButton>
#include <QInputDialog>
#include <QProgressBar>

Zork::Zork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zork)
{
    ui->setupUi(this);
    // Hide my take buttons by default
    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);
    ui->TakeZ->setVisible(false);

    game.createRooms();

    takeButtons();
    string charName = (QInputDialog::getText(parent,"Character Customisation","Enter your name:")).toStdString();
    player.setName(charName);
    ui->outputText->append(game.printWelcome(player.getName()));
    ui->healthBar->setValue(30);
}

Zork::~Zork()
{
    delete ui;
}


void Zork::on_teleport_clicked()
{
    ui->outputText->append("Teleported");
    game.teleport();
    ui->outputText->append(QString::fromStdString(game.currentRoom->longDescription()));
    takeButtons();
}

void Zork::go(string direction) {
    ui->outputText->append(game.go(direction));
    takeButtons();
}

void Zork::on_goNorth_clicked(){
    go("north");
    ui->healthBar->setValue(ui->healthBar->value()-20);
}

void Zork::on_goEast_clicked(){
    go("east");
}

void Zork::on_goSouth_clicked(){
    go("south");
}

void Zork::on_goWest_clicked(){
    go("west");
}

void Zork::on_map_clicked(){
    ui->outputText->append(game.map());
}

void Zork::on_healthBar_valueChanged(int value)
{
    if(ui->healthBar->value()<1)
        ui->outputText->append("Oh dear, you are dead.");
}

void Zork::takeButtons(){
//    QPushButton *slotButtons[3];
//    QVBoxLayout* layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
//    for(int i = 0; i < game.currentRoom->numberOfItems(); i++)
//    {
//        slotButtons[i] = new QPushButton;
//        slotButtons[i]->setText(QString::fromStdString((game.currentRoom->itemsInRoom[i]).getShortDescription()));
//        ui->scrollAreaWidgetContents->layout()->addWidget(slotButtons[i]);
//    }

    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);
    ui->TakeZ->setVisible(false);

    // check if room has (max 3) items
    // cycle through list of items, activating buttons and setting text to item description
    if(game.currentRoom->numberOfItems()!=0){
        if(game.currentRoom->numberOfItems()>0){
            ui->TakeX->setVisible(true);
            ui->TakeX->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[0].getShortDescription()));
        }
        if(game.currentRoom->numberOfItems()>1){
            ui->TakeY->setVisible(true);
            ui->TakeY->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[1].getShortDescription()));
        }
        if(game.currentRoom->numberOfItems()>2){
            ui->TakeZ->setVisible(true);
            ui->TakeZ->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[2].getShortDescription()));
        }
    }
}

void Zork::on_TakeX_clicked()
{
//    player.addItem(currentRoom->itemsInRoom[0]);
    game.currentRoom->removeItemFromRoom("x");
}





/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
//bool Zork::processCommand(Command command) {
//    if (command.isUnknown()) {
//        cout << "invalid input"<< endl;
//        return false;
//    }

//    string commandWord = command.getCommandWord();

//    if (commandWord.compare("take") == 0)
//    {
//        if (!command.hasSecondWord()) {
//        cout << "incomplete input"<< endl;
//        }
//        else
//         if (command.hasSecondWord()) {
//        cout << "you're trying to take " + command.getSecondWord() << endl;
//        int location = currentRoom->removeItemFromRoom(command.getSecondWord());
//        if (location  < 0 )
//            cout << "item is not in room" << endl;
//        else
//            cout << "item is in room" << endl;
//            cout << "index number " << + location << endl;
//            cout << currentRoom->longDescription() << endl;
//        }
//    }

//    else if (commandWord.compare("put") == 0)
//    {

//    }

//    {
//    if (!command.hasSecondWord()) {
//        cout << "incomplete input"<< endl;
//        }
//        else
//            if (command.hasSecondWord()) {
//            cout << "you're adding " + command.getSecondWord() << endl;
//            itemsInRoom.push_Back;
//        }
//    }

//    else if (commandWord.compare("quit") == 0) {
//        if (command.hasSecondWord())
//            cout << "overdefined input"<< endl;
//        else
//            return true; /**signal to quit*/
//    }
//    return false;
//}
///** COMMANDS **/
//void Zork::printHelp() {
//    cout << "\nvalid inputs are; " << endl;
//    parser.showCommands();

//}

