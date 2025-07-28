/*#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>

class Player : public Character {
private:
    int score;
public:
    void setScore(int s);
    int getScore() const;
    void setLocation(Location* loc);
    Location* getLocation() const;
    void collectItems(Location* loc);
    bool moveTo(const std::string& direction);
    std::string drinkPotions();
    std::string combat();
};

#endif // PLAYER_H
*/


#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <string>

class Location;
class Player : public Character {
private:
    int score;
public:
    void setScore(int s);
    int getScore() const;

    void setLocation(Location* loc);
    Location* getLocation() const;

    void collectItems(Location* loc);
    bool moveTo(const std::string& direction);

    std::string drinkPotions();
    std::string combat();
};

#endif // PLAYER_H

