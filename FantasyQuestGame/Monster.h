#pragma once
#include "Character.h"
#include <string>

class Monster : public Character {
private:
    std::string swansong;
    int bounty;
    int power;

public:
    Monster(const std::string& name, const std::string& desc, const std::string& swansong);

    void setSwansong(const std::string& s);
    std::string getSwansong() const;

    void setBounty(int b);
    int getBounty() const;

    void setPower(int pw);
    int getPower() const;
};
