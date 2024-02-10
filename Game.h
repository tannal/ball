#pragma once

#include "SpaceShip.h"

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
        SpaceShip ship;
};