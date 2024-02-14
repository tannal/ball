#pragma once

#include "SpaceShip.h"
#include "Obstacle.h"
#include "Alien.h"
class Game {
    public:
        Game();
        ~Game();
        void Update();
        void Draw();
        void Unload();
        void HanleInput();
        bool IsGameOver();

    private:
        void DeleteInactiveLasers();
        std::vector<Obstacle> createObstacles();
        std::vector<Alien> createAliens();
        std::vector<Obstacle> obstacles;
        std::vector<Alien> aliens;
        SpaceShip ship;
};