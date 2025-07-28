#pragma once
#include "Item.h"
#include <string>

class Weapon : public Item {
private:
    int power;

public:
    Weapon(const std::string& name, int p);  // ���캯��

    void setPower(int p);
    int getPower() const;
};
