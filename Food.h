#ifndef FOOD_H
#define FOOD_H

#include "Item.h"


class Food : public Item
{
public:
    Food(string, int);
    int healValue;
    virtual int getValue();
};

#endif // FOOD_H
