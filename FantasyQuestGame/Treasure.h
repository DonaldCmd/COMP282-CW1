#pragma once
#include "Item.h"

class Treasure : public Item {
private:
    int value;
public:
    Treasure(const std::string& name, int v);
    int getValue() const;
    void setValue(int v);
};

