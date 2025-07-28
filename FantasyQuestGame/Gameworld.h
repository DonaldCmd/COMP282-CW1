
#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include <vector>
#include "Location.h"
#include "Player.h"




class Gameworld {
private:
    //Gameworld();
    //void loadworld();
    bool gameOver;
   // Player* getPlayer();
    Player* player;// 添加这一行
    std::vector<Location*>locations;
    
    

public:
    Gameworld();
    void loadworld();
    bool isGameOver() const;
    void setGameOver(bool gameOver);
    void loadWorld();
    //std::vector<Location*>locations;
   // Player* player;  // ⬅ 假设你已经有这个变量
    Player* getPlayer();

};

#endif // GAMEWORLD_H



