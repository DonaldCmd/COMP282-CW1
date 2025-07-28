#include "Treasure.h"

Treasure::Treasure(const std::string& name, int v) : Item(name), value(v) {}
int Treasure::getValue() const { return value; }
void Treasure::setValue(int v) { value = v; }