/*  Moving North will hurt
 *  Items may heal or hurt you
 *  Room H will win the game
 */

#include "Zork.h"
#include "ui_zork.h"

Zork::Zork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zork)
{
    ui->setupUi(this);
    // Hide my take buttons by default
    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);

    game.createRooms();

    takeButtons();
    string charName = (QInputDialog::getText(parent,"Character Customisation","Enter your name:")).toStdString();
    player.setName(charName);
    ui->outputText->append(game.printWelcome(player.getName()));
    ui->healthBar->setValue(player.health);
}

Zork::~Zork()
{
    delete ui;
}


void Zork::gameOver(string title, string body, string desc){
    QMessageBox msgBox;
    msgBox.setWindowTitle(QString::fromStdString(title));
    msgBox.setText(QString::fromStdString(body) + QString::fromStdString(desc));
    QPushButton *abortButton = msgBox.addButton(QMessageBox::Close);

    msgBox.exec();
    if (msgBox.clickedButton() == abortButton) {
        QApplication::quit();
    }
}

void Zork::gameWon(string desc){
    gameOver("Winner Winner", "WIN!\n", desc);

}

void Zork::gameLost(string desc){
    gameOver("Game over.", "L!\n", desc);
}

void Zork::checkWin(){
    if(game.currentRoom->type=="win")
        gameWon("You have reached the magical destination");
}

void Zork::on_teleport_clicked()
{
    ui->outputText->append("Teleported");
    game.teleport();
    ui->outputText->append(QString::fromStdString(game.currentRoom->longDescription()));
    takeButtons();
    checkWin();
}

void Zork::go(string direction) {
    ui->outputText->append(game.go(direction));
    checkWin();
    takeButtons();
}

void Zork::healthChange(int delta){
    ui->outputText->append(QString::fromStdString(to_string(delta)));
    if(delta < 0)
        ui->outputText->append("Ouch!");
    else if (delta > 0)
        ui->outputText->append("Yum!");

    player.health += delta;
    if(player.health<1){
        ui->healthBar->setValue(0);
        gameLost("Oh dear, you are dead.");
    }
    ui->healthBar->setValue(player.health);
}

void Zork::on_goNorth_clicked() {
    go("north");
    healthChange(-20);
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

void Zork::on_inventory_clicked()
{
    ui->outputText->append(QString::fromStdString(player.longDescription()));
}

void Zork::on_TakeX_clicked()
{
     takeItem(ui->TakeX);
}

void Zork::on_TakeY_clicked()
{
    takeItem(ui->TakeY);
}


void Zork::takeItem(QPushButton* takeBtn){
    string itemText = (takeBtn->text()).toStdString();
    string r = "Take ";
    string::size_type i = itemText.find(r);
    if (i != std::string::npos)
       itemText.erase(i, r.length());

    Item * toAdd = game.currentRoom->getItemFromString(itemText);
    player.addItem(toAdd);
    game.currentRoom->removeItemFromRoom(itemText);
    takeBtn->setVisible(false);

    healthChange((toAdd)->getValue());
}

void Zork::takeButtons(){

    ui->TakeX->setVisible(false);
    ui->TakeY->setVisible(false);

    // check if room has (max 3) items
    // cycle through list of items, activating buttons and setting text to item description
    if(game.currentRoom->numberOfItems()!=0){
        if(game.currentRoom->numberOfItems()>0){
            ui->TakeX->setVisible(true);
            ui->TakeX->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[0]->getShortDescription()));
        }
        if(game.currentRoom->numberOfItems()>1){
            ui->TakeY->setVisible(true);
            ui->TakeY->setText(QString::fromStdString("Take " + game.currentRoom->itemsInRoom[1]->getShortDescription()));
        }
    }
}
