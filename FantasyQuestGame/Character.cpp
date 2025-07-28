#include "Character.h"
#include "Item.h"
#include "Location.h"
#include <algorithm>
#include <sstream>


int Character::getArmourProtection() {
    int total = 0;

    for (auto item : inventory) {
        std::string name = item->getName();

        // 检查名称中是否包含 Armour 字样
        if (name.find("Armour") != std::string::npos || name.find("Shield") != std::string::npos) {
            // 简化写死的防御值（可扩展为配置）
            if (name == "Bronze Armour") total += 8;
            else if (name == "Iron Plate") total += 15;
            else if (name == "Shadow Cloak") total += 5;
            else if (name == "Steel Shield") total += 10;
            else if (name == "Plate Armour") total += 20;
            // 可继续添加
        }
    }

    return total;
}


void Character::addItem(Item* item) {
    inventory.push_back(item);
}

void Character::removeItem(Item* item) {
    inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
}

void Character::dropItem(Item* item) {
    if (location) location->addItem(item);
    removeItem(item);
}

Location* Character::getLocation() const {
    return location;
}

bool Character::moveTo(Location* newLocation) {
    if (newLocation) {
        location = newLocation;
        return true;
    }
    return false;
}

void Character::setSkill(int sk) {
    skill = sk;
}

int Character::getSkill() const {
    return skill;
}

void Character::setHitpoints(int hp) {
    hitpoints = hp;
}

int Character::getHitpoints() const {
    return hitpoints;
}

void Character::setName(const std::string& newName) {
    name = newName;
}

std::string Character::getName() const {
    return name;
}

void Character::setArmour(int ar) {
    armour = ar;
}

int Character::getArmour() const {
    return armour;
}

void Character::takeHit(int hit) {
    
    int reduction = getArmourProtection();  // 可从装备中获取护甲值
    int actual = std::max(1, hit - reduction);  // 至少造成1点伤害
    hitpoints -= actual;
}

std::string Character::getInventory() const {
    if (inventory.empty()) return "Your inventory is empty.";
    std::ostringstream oss;
    oss << "Inventory: ";
    for (auto item : inventory) {
        oss << item->getName() << ", ";
    }
    return oss.str();
}