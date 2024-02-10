#pragma once

#include <raylib.h>
#include <vector>
#include "Laser.h"
class SpaceShip
{
public:
    SpaceShip();
    ~SpaceShip();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();

    std::vector<Laser> lasers;

private:
    Texture2D texture;
    Vector2 position;
    double lastFireTime;
};