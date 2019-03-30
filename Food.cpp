#include "Food.h"

Food::Food(string desc, int val, double sod)
    : Item(desc){
    this->healValue = val;
    this->sodium = sod;
}
int Food::getValue(){
    return this->healValue;
}

double Food::getSodium(){
    return this->sodium;
}
