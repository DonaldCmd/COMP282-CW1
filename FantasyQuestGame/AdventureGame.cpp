#include "Gameworld.h"
#include "Location.h"
#include "Player.h"
#include <iostream>
#include <map>
#include <string>
#include "Item.h"


extern Player* player;

int main() {
    Gameworld world;
    world.loadWorld();

    Player* player = world.getPlayer();

    std::string input;

    std::cout << "Welcome to Fantasy Quest Adventure!" << std::endl;



    while (!world.isGameOver()) {
        // 显示玩家当前状态
        std::cout << "\nHero Status:\n";
        std::cout << "  Hitpoints: " << player->getHitpoints() << "\n";
        std::cout << "  Skill: " << player->getSkill() << "\n";
        std::cout << "  Armour: " << player->getArmourProtection() << "\n";


        // 显示当前物品清单
        std::cout << "  Inventory: ";
        std::string inv = player->getInventory();
        std::cout << (inv.empty() ? "Empty\n" : inv + "\n");

        Location* current = player->getLocation();
        std::cout << "\nYou are at: " << current->getName() << std::endl;
        std::cout << current->getDescription() << std::endl;
        std::cout << "Available exits: " << current->showExits() << std::endl;

        // 🌟 显示当前位置物品
        std::vector<Item*> items = current->getItems();
        if (!items.empty()) {
            std::cout << "Items here: ";
            for (auto item : items) {
                std::cout << item->getName() << ", ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "There are no items here." << std::endl;
        }

        // ✅ 显示该地点的怪物
        std::vector<Monster*> monsters = current->getMonsters();
        if (!monsters.empty()) {
            std::cout << "Monsters here:\n";
            for (auto m : monsters) {
                std::cout << "- " << m->getName() << ": " << 
                    //m->getDescription()
                    //<< 
                    "\n";
                std::cout << "    Hitpoints: " << m->getHitpoints()
                    << ", Skill: " << m->getSkill()
                    << ", Power: " << m->getPower()
                    << ", Armour: " << m->getArmourProtection() << "\n";
            }
        }

        std::cout << "\nEnter direction (n/s/e/w), or 'collect', 'drink', 'inv', or 'quit': ";
        std::getline(std::cin, input);

        if (input == "quit") {
            world.setGameOver(true);
        }
        else if (input == "collect") {
            player->collectItems(current);
            std::cout << "You collected all items at this location." << std::endl;
        }
        else if (input == "drink") {
            std::cout << player->drinkPotions() << std::endl;
        }
        else if (input == "inv") {
            std::cout << player->getInventory() << std::endl;
        }
        /*else if (input == "n" || input == "s" || input == "e" || input == "w") {
            Location* next = current->getExit(input);
            if (next) {
                player->setLocation(next);
            }
            else {
                std::cout << "No exit in that direction." << std::endl;
            }
        }

        else {
            std::cout << "Unknown command." << std::endl;
        }*/
        else {
            std::map<std::string, std::string> alias = { {"n", "NORTH"}, {"s", "SOUTH"}, {"e", "EAST"}, {"w", "WEST"} };
            if (alias.find(input) != alias.end()) {
                if (!player->moveTo(alias[input])) {
                    std::cout << "No exit in that direction." << std::endl;
                }
            }
            else {
                std::cout << "Unknown command." << std::endl;
            }
        }
    }

    std::cout << "\nGame Over. Thanks for playing!" << std::endl;
    return 0;
}