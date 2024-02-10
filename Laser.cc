#include "Laser.h"


Laser::Laser(Vector2 position, int speed): position(position), speed(speed)
{
    texture = LoadTexture("./res/laser.png");
    active = true;
}

Laser::~Laser()
{
    UnloadTexture(texture);
}

void Laser::Draw() {
    // DrawTexture(texture, position.x, position.y, WHITE);

    DrawRectangle(position.x, position.y, 4, 15, WHITE);
}

void Laser::Update() {
    position.y += speed;

    if(active) {
        if(position.y < 0 || position.y > GetScreenHeight()) {
            active = false;
        }
    }
}

bool Laser::IsActive() {
  return active;
}
