#include "Player.h"
#include "Location.h"
#include "Potion.h"
#include <sstream>


void Player::setScore(int s) {
    score = s;
}

int Player::getScore() const {
    return score;
}

void Player::setLocation(Location* loc) {
    location = loc;
}

Location* Player::getLocation() const {
    return location;
}

void Player::collectItems(Location* loc) {
    std::vector<Item*> items = loc->getItems();
    for (auto item : items) {
        addItem(item);
        loc->removeItem(item);
    }
}

bool Player::moveTo(const std::string& direction) {
    Location* next = location->getExit(direction);
    if (next) {
        location = next;
        return true;
    }
    return false;
}

std::string Player::drinkPotions() {
    std::vector<Item*> kept;
    int totalHealed = 0;
    for (auto item : inventory) {
        Potion* potion = dynamic_cast<Potion*>(item);
        if (potion) {
            totalHealed += potion->getStrength();
        }
        else {
            kept.push_back(item);
        }
    }
    inventory = kept;
    hitpoints += totalHealed;

    std::ostringstream oss;
    if (totalHealed > 0) {
        oss << "You drink potions and recover " << totalHealed << " HP.";
    }
    else {
        oss << "You have no potions to drink.";
    }
    return oss.str();
}


std::string Player::combat() {
    return "Combat result";
}

