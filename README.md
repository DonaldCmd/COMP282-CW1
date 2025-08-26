# Fantasy Quest Adventure Game

This repository contains the coursework project for the COMP282 module at the University of Liverpool (2025). The project is a text-based console adventure game written in C++14 using object-oriented programming principles. The game features a navigable map, a turn-based combat system, an item and inventory system, and a final boss encounter.  
**Note: This code is for educational reference only. Please do not plagiarize.**

---

## 🧾 Project Overview

- **Type**: Console-based text adventure game  
- **Language**: C++14  
- **Paradigm**: Object-Oriented Programming (OOP)  
- **Development Environment**: Visual Studio 2022  
- **Goal**: Explore a connected world, battle monsters, collect items, and defeat the final boss to obtain the Eldritch Ring.

---

## 🎮 Features

- **Complete Game System**: Includes location navigation, combat mechanics, inventory and item collection, and win condition.
- **Map Navigation**: A world made up of 17 interconnected locations using `map` and `vector` STL containers to manage direction and connectivity.
- **Modular Class Design**:  
  Structured with OOP—classes include `Gameworld`, `Character`, `Player`, `Monster`, `Boss`, `Item`, and derived types like `Potion`, `Weapon`, and `Treasure`.
- **Turn-Based Combat**:  
  Dice-based attack rolls, damage/armor calculations, and support for handling multiple enemies.
- **Inventory System**:  
  Categorized inventory with automatic sorting, potion consumption for healing, and command-based interaction.

---

## 📁 Project Structure

## ├── AdventureGame.cpp      // Entry point and game loop
## ├── Gameworld.h / .cpp     // Game world initialization and logic
## ├── Character.h / .cpp     // Base character class
## ├── Player.h / .cpp        // Player logic and inventory
## ├── Monster.h / .cpp       // Monster class
## ├── Boss.h / .cpp          // Final boss subclass
## ├── Item.h / .cpp          // Item base class
## ├── Potion.h / .cpp        // Potion subclass
## ├── Weapon.h / .cpp        // Weapon subclass
## ├── Treasure.h / .cpp      // Treasure subclass
## ├── Location.h / .cpp      // Location system and exit handling

## 🕹 Gameplay Commands

## Command       Description
## -----------------------------------------------
## north  / n    Move north
## south  / s    Move south
## east   / e    Move east
## west   / w    Move west
## collect       Collect all items in the location
## inventory / inv   View categorized inventory
## drink         Consume all potions to heal
## quit   / q    Exit the game

## Combat will automatically begin if a monster is present in the room.

