#include "Food.h"

Food::Food(string desc, int val)
    : Item(desc){
    this->healValue = val;
}
int Food::getValue(){
    return this->healValue;
}
