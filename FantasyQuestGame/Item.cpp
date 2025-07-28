#include "Item.h"

Item::Item(const std::string& name) : name(name) {}

void Item::setName(const std::string& newName) {
    name = newName;
}

std::string Item::getName() const {
    return name;
}