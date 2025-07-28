#include "Potion.h"

Potion::Potion(const std::string& name, int s) : Item(name), strength(s) {}
int Potion::getStrength() const { return strength; }
void Potion::setStrength(int s) { strength = s; }
