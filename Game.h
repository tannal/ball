#pragma once

#include "SpaceShip.h"
#include "Obstacle.h"
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
        std::vector<Obstacle> obstacles;
        SpaceShip ship;
};