#include "Location.h"
#include "Item.h"
#include "Monster.h"
#include <sstream>
#include <algorithm>

void Location::setName(const std::string& newName) {
    name = newName;
}

std::string Location::getName() const {
    return name;
}

void Location::setDescription(const std::string& newDesc) {
    description = newDesc;
}

std::string Location::getDescription() const {
    return description;
}

void Location::addExit(const std::string& direction, Location* loc) {
    exits[direction] = loc;
}

std::string Location::showExits() const {
    std::ostringstream oss;
    for (const auto& pair : exits) {
        oss << pair.first << " ";
    }
    return oss.str();
}

Location* Location::getExit(const std::string& direction) const {
    auto it = exits.find(direction);
    return it != exits.end() ? it->second : nullptr;
}

void Location::addMonster(Monster* monster) {
    monsters.push_back(monster);
}

void Location::delMonster(Monster* monster) {
    monsters.erase(std::remove(monsters.begin(), monsters.end(), monster), monsters.end());
}

std::vector<Monster*> Location::getMonsters() const {
    return monsters;
}

void Location::addItem(Item* item) {
    items.push_back(item);
}

std::vector<Item*> Location::getItems() const
{
    return items;
}

void Location::removeItem(Item* item) {
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end()) {
        items.erase(it);
    }
}


