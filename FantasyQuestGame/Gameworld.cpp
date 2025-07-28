


// =============================
// 文件：Gameworld.cpp（Gameworld 类）
// =============================

#include "Gameworld.h"
#include "Location.h"
#include "Player.h"
#include "Monster.h"
#include <map>
#include <iostream>
#include <string>
#include "Potion.h"
#include "Weapon.h"
#include "Treasure.h"

#include "Gameworld.h"
#include "Weapon.h"
#include "Potion.h"
#include "Treasure.h"
#include "Monster.h"
#include "Item.h"
#include <string>


extern Player* player;
Gameworld::Gameworld() {
    loadWorld();  // 构造时加载地图
}

Player* Gameworld::getPlayer() {
    return player;
}


Player* player = nullptr;
std::map<int, Location*> locations;

bool Gameworld::isGameOver() const {
    return gameOver;
}

void Gameworld::setGameOver(bool go) {
    gameOver = go;
}


void Gameworld::loadWorld() {
    locations.resize(33);
    // Task 2: 构建地图与地点连接（无参构造 + set 方法）
    locations[19] = new Location();
    locations[19]->setName("The Central Nexus");
    locations[19]->setDescription("An ancient crossroads where time and space intertwine.");

    locations[1] = new Location();
    locations[1]->setName("The Great Abercromby Gates");
    locations[1]->setDescription("Massive stone gates carved with arcane runes.");

    locations[2] = new Location();
    locations[2]->setName("The Guildhall of Scholars");
    locations[2]->setDescription("A grand hall where traders, scribes, and mysterious figures gather.");

    locations[3] = new Location();
    locations[3]->setName("The Forbidden Harold Temple");
    locations[3]->setDescription("Ancient tomes whisper secrets from their dusty shelves.");

    locations[5] = new Location();
    locations[5]->setName("The Thompson Observatory");
    locations[5]->setDescription("A domed tower where the stars reveal glimpses of fate.");

    locations[6] = new Location();
    locations[6]->setName("The Holt Enclave");
    locations[6]->setDescription("A ruined amphitheater where echoes of past lectures still resonate.");

    locations[7] = new Location();
    locations[7]->setName("The Reilly Battlegrounds");
    locations[7]->setDescription("A coliseum of stone and steel, where warriors train and champions rise.");

    locations[9] = new Location();
    locations[9]->setName("The Rendall Arena");
    locations[9]->setDescription("The echoes of battle cries ring through the ruined walls.");

    locations[13] = new Location();
    locations[13]->setName("The Chatham Archives");
    locations[13]->setDescription("Endless rows of scrolls, each documenting powerful relics lost to time.");

    locations[14] = new Location();
    locations[14]->setName("The Mountford Keep");
    locations[14]->setDescription("A towering fortress where ancient warriors once trained.");

    locations[15] = new Location();
    locations[15]->setName("The Sidney Vault");
    locations[15]->setDescription("A labyrinth of books and stone where scholars vanished centuries ago.");

    locations[20] = new Location();
    locations[20]->setName("The Victoria Spire");
    locations[20]->setDescription("A towering spire with a celestial beacon at its peak.");

    locations[26] = new Location();
    locations[26]->setName("The Guilded Forge");
    locations[26]->setDescription("A legendary forge where artifacts of immense power were once crafted.");

    locations[29] = new Location();
    locations[29]->setName("The Fenwick Rift");
    locations[29]->setDescription("A tear in reality...");

    locations[30] = new Location();
    locations[30]->setName("The Scholar's Ascent");
    locations[30]->setDescription("A winding staircase that tests the mind as much as the body.");

    locations[31] = new Location();
    locations[31]->setName("The Octagon Spire");
    locations[31]->setDescription("A mystical tower containing knowledge beyond mortal comprehension.");

    locations[32] = new Location();
    locations[32]->setName("The Final Gateway");
    locations[32]->setDescription("A portal leading to the realm beyond.");

    // 出口连接
    locations[19]->addExit("WEST", locations[1]);
    locations[19]->addExit("NORTH", locations[2]);
    locations[19]->addExit("EAST", locations[3]);
    locations[1]->addExit("EAST", locations[19]);
    locations[2]->addExit("SOUTH", locations[19]);
    locations[2]->addExit("NORTH", locations[5]);
    locations[2]->addExit("EAST", locations[13]);
    locations[2]->addExit("WEST", locations[15]);
    locations[5]->addExit("SOUTH", locations[2]);
    locations[5]->addExit("NORTH", locations[30]);
    locations[5]->addExit("EAST", locations[31]);
    locations[30]->addExit("SOUTH", locations[5]);
    locations[30]->addExit("WEST", locations[29]);
    locations[29]->addExit("EAST", locations[30]);
    locations[29]->addExit("SOUTH", locations[32]);
    locations[32]->addExit("NORTH", locations[29]);
    locations[31]->addExit("NORTH", locations[20]);
    locations[31]->addExit("WEST", locations[5]);
    locations[20]->addExit("SOUTH", locations[31]);
    locations[13]->addExit("WEST", locations[2]);
    locations[15]->addExit("EAST", locations[2]);
    locations[3]->addExit("SOUTH", locations[9]);
    locations[3]->addExit("WEST", locations[19]);
    locations[3]->addExit("NORTH", locations[6]);
    locations[3]->addExit("EAST", locations[14]);
    locations[6]->addExit("SOUTH", locations[3]);
    locations[6]->addExit("EAST", locations[26]);
    locations[14]->addExit("SOUTH", locations[7]);
    locations[14]->addExit("NORTH", locations[26]);
    locations[14]->addExit("WEST", locations[3]);
    locations[9]->addExit("NORTH", locations[3]);
    locations[9]->addExit("WEST", locations[7]);
    locations[7]->addExit("NORTH", locations[14]);
    locations[7]->addExit("EAST", locations[9]);
    locations[26]->addExit("SOUTH", locations[14]);
    locations[26]->addExit("WEST", locations[6]);

    // 添加怪物
    Monster* m1 = new Monster("Raider", "A swift and ruthless attacker.", "The final blow before falling.");
    m1->setSkill(3); m1->setHitpoints(30); m1->setPower(10); m1->setArmour(5);
    locations[6]->addMonster(m1);

    Monster* m2 = new Monster("Warrior", "A stalwart defender of ancient traditions.", "Dies honourably in battle.");
    m2->setSkill(4); m2->setHitpoints(40); m2->setPower(12); m2->setArmour(8);
    locations[5]->addMonster(m2);

    Monster* m3 = new Monster("Brute", "A formidable opponent with crushing strength.", "Falls with a deafening roar.");
    m3->setSkill(2); m3->setHitpoints(50); m3->setPower(15); m3->setArmour(10);
    locations[29]->addMonster(m3);

    Monster* m4 = new Monster("Troll", "An ancient creature lurking beneath the shadows.", "Its final roar shakes the earth.");
    m4->setSkill(2); m4->setHitpoints(60); m4->setPower(18); m4->setArmour(12);
    locations[29]->addMonster(m4);

    Monster* m5 = new Monster("Bandit", "A cunning thief with a taste for blood.", "Slumps quietly after a fatal misstep.");
    m5->setSkill(4); m5->setHitpoints(45); m5->setPower(20); m5->setArmour(7);
    locations[2]->addMonster(m5);

    Monster* m6 = new Monster("Wraith", "An ethereal entity from beyond the grave.", "Fades into the mist with a haunting whisper.");
    m6->setSkill(2); m6->setHitpoints(35); m6->setPower(8); m6->setArmour(4);
    locations[30]->addMonster(m6);

    Monster* m7 = new Monster("Knight", "A noble warrior sworn to protect his honour.", "Falls with dignity in his final charge.");
    m7->setSkill(5); m7->setHitpoints(50); m7->setPower(18); m7->setArmour(12);
    locations[31]->addMonster(m7);

    Monster* m8 = new Monster("Sprite", "A mischievous and elusive fae creature.", "Disappears with a final burst of light.");
    m8->setSkill(1); m8->setHitpoints(25); m8->setPower(10); m8->setArmour(3);
    locations[9]->addMonster(m8);

    // 添加物品到地点
    locations[19]->addItem(new Weapon("Rusty Sword",5));
    locations[1]->addItem(new Treasure("Old Coin", 25));
    locations[2]->addItem(new Potion("Red Potion", 40));
    //locations[3]->addItem(new Armour("Bronze Armour", 8));
    locations[3]->addItem(new Item("Bronze Armour"));

    // 添加物品到怪物
    m1->addItem(new Potion("Small Heal", 20));
    m2->addItem(new Treasure("Crystal Ring", 60));
    m3->addItem(new Weapon("Spiked Mace",10));
    //m4->addItem(new Armour("Iron Plate", 15));
    m4->addItem(new Item("Iron Plate"));
    m5->addItem(new Potion("Elixir", 35));
    m6->addItem(new Treasure("Ghost Pendant", 40));
    m7->addItem(new Weapon("Knight's Blade",12));
    //m8->addItem(new Armour("Shadow Cloak", 5));
    m8->addItem(new Item("Shadow Cloak"));


    // 初始化玩家
    player = new Player();
    player->setName("Hero");
    player->setSkill(6);
    player->setArmour(0);
    player->setHitpoints(50);
    player->setLocation(locations[19]);

    

}
/*Player* Gameworld::getPlayer() {
    return player;
}*/



