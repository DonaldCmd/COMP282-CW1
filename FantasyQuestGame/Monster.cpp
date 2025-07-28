#include "Monster.h"

Monster::Monster(const std::string& name, const std::string& desc, const std::string& swansong) {
    setName(name);
    //setDescription(desc);
    setSwansong(swansong);
}

void Monster::setSwansong(const std::string& s) {
    swansong = s;
}

std::string Monster::getSwansong() const {
    return swansong;
}

void Monster::setPower(int pw) {
    power = pw;
}

int Monster::getPower() const {
    return power;
}

void Monster::setBounty(int b) {
    bounty = b;
}

int Monster::getBounty() const {
    return bounty;
}
