
#include "Alien.h"

Alien::Alien(Vector2 position, int type) {
    this->position = position;
    this->type = type;

    switch(type) {
        case 1:
            this->image = LoadTexture("res/alien_1.png");
            break;
        case 2:
            this->image = LoadTexture("res/alien_2.png");
            break;
        case 3:
            this->image = LoadTexture("res/alien_3.png");
            break;
    }
}


void Alien::Update() {
    position.y += 1;
}


void Alien::Draw() {
    DrawTexture(image, position.x, position.y, WHITE);
}

