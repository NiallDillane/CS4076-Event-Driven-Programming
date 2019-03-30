#ifndef FOOD_H
#define FOOD_H

#include "item.h"


class Food : public Item
{
public:
    Food(string, int, double);
    virtual int getValue();
    virtual double getSodium();
private:
    int healValue;
    double sodium;
};

#endif // FOOD_H
