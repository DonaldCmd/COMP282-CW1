/*#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>

class Item;
class Monster;

class Location {
private:
    std::string name;
    std::string description;
    std::vector<Item*> items;
    std::map<std::string, Location*> exits;
    std::vector<Monster*> monsters;
public:
    void setName(const std::string& newName);
    std::string getName() const;
    void setDescription(const std::string& newDesc);
    std::string getDescription() const;
    void addExit(const std::string& direction, Location* loc);
    std::string showExits() const;
    void addMonster(Monster* monster);
    void delMonster(Monster* monster);
    void addItem(Item* item);
};

#endif // LOCATION_H
*/

#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>
#include"Monster.h"
#include"Item.h"
class Item;
class Monster;
class Location {
private:
    std::string name;
    std::string description;
    std::vector<Item*> items;
    std::map<std::string, Location*> exits;
    std::vector<Monster*> monsters;
    //std::vector<Monster*> getMonsters() const;
public:
    void setName(const std::string& newName);
    std::string getName() const;

    void setDescription(const std::string& newDesc);
    std::string getDescription() const;

    void addExit(const std::string& direction, Location* loc);
    std::string showExits() const;
    Location* getExit(const std::string& direction) const;

    void addMonster(Monster* monster);
    void delMonster(Monster* monster);

    void addItem(Item* item);
    void removeItem(Item* item);   
    std::vector<Item*> getItems() const;
    // ✅ 新增声明
    std::vector<Monster*> getMonsters() const;
};

#endif // LOCATION_H


