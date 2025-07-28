// Potion.h
#pragma once
#include "Item.h"

class Potion : public Item {
private:
    int strength;
public:
    Potion(const std::string& name, int s);
    int getStrength() const;
    void setStrength(int s);
};

