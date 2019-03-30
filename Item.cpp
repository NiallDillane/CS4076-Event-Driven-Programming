#include "Item.h"

Item::Item (string inDescription, double inWeightGrams/**, int weaponCheck*/) {
	description = inDescription;
    setWeight(inWeightGrams);
	/**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription) {
	description = inDescription;
}

Item::Item(string inDescription, string type, int value) {
    this->description = inDescription;
    this->type = type;
    this->value = value;
}

Item::Item(){}

Item::~Item(){}

void Item::setWeight(double inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(int inValue)
{
    value = inValue;
}

string Item::getType(){
    return this->type;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
    return "Item: " + description + ".\n";
}

