#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
class Item;
class Location;

class Character {
protected:
    std::string name;
    std::string description;
    int armour;
    int hitpoints;
    int skill;
    Location* location;
    std::vector<Item*> inventory;
public:
    int getArmourProtection();
    void addItem(Item* item);
    void removeItem(Item* item);
    void dropItem(Item* item);
    Location* getLocation() const;
    bool moveTo(Location* newLocation);
    void setSkill(int sk);
    int getSkill() const;
    void setHitpoints(int hp);
    int getHitpoints() const;
    void setName(const std::string& newName);
    std::string getName() const;
    void setArmour(int ar);
    int getArmour() const;
    void takeHit(int hit);
    std::string getInventory() const;
};

#endif // CHARACTER_H

