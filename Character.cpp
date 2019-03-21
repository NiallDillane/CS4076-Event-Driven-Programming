#include "Character.h"

Character::Character(){}

Character::Character(string description) {
	this->description = description;
}
void Character::setName(string name){
    this->name = name;
}
string Character::getName(){
    return this->name;
}
string Character::getHealth(){
    std::ostringstream stm ;
    stm << this->health ;
    return stm.str();
}
void Character::addItem(Item &item) {
    itemsInCharacter.push_back(item);
}
void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}
string Character::longDescription(){
  string ret = this->description;
  ret += "\n Inventory:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription();
  return ret;
}
