#include "Weapon.h"

Weapon::Weapon(const std::string& name, int p)
    : Item(name), power(p) {
}

void Weapon::setPower(int p) {
    power = p;
}

int Weapon::getPower() const {
    return power;
}
