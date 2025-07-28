#include "Character.h"
#include "Item.h"
#include "Location.h"
#include <algorithm>
#include <sstream>


int Character::getArmourProtection() {
    int total = 0;

    for (auto item : inventory) {
        std::string name = item->getName();

        // ����������Ƿ���� Armour ����
        if (name.find("Armour") != std::string::npos || name.find("Shield") != std::string::npos) {
            // ��д���ķ���ֵ������չΪ���ã�
            if (name == "Bronze Armour") total += 8;
            else if (name == "Iron Plate") total += 15;
            else if (name == "Shadow Cloak") total += 5;
            else if (name == "Steel Shield") total += 10;
            else if (name == "Plate Armour") total += 20;
            // �ɼ������
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
    
    int reduction = getArmourProtection();  // �ɴ�װ���л�ȡ����ֵ
    int actual = std::max(1, hit - reduction);  // �������1���˺�
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