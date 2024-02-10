#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
    texture = LoadTexture("./res/spaceship.png");
    position.x = GetScreenWidth() / 2 - texture.width / 2;
    position.y = GetScreenHeight() - 40;

    lastFireTime = 0;
}

SpaceShip::~SpaceShip()
{
    UnloadTexture(texture);
}

void SpaceShip::Draw()
{
    DrawTexture(texture, position.x, position.y, WHITE);
}

void SpaceShip::MoveRight()
{
    position.x += 5;

    if(position.x < 0) {
        position.x = 0;
    }
}

void SpaceShip::FireLaser()
{
    if(GetTime() - lastFireTime >= 0.35) {
        lastFireTime = GetTime();
        lasers.push_back(Laser({position.x + 20, position.y}, -1));
    }
}

void SpaceShip::MoveLeft()
{
    position.x -= 5;

    if(position.x > GetScreenWidth() - texture.width) {
        position.x = GetScreenWidth() - texture.width;
    }
}
