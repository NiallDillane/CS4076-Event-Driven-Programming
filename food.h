#ifndef FOOD_H
#define FOOD_H

#include "item.h"


class food : public Item
{
public:
    food(string, int);
    int healValue;
    int getValue();
};

#endif // FOOD_H
