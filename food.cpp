#include "food.h"

food::food(string desc, int val)
    : Item(desc){
    this->healValue = val;
}
int food::getValue(){
    return this->healValue;
}
