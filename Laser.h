
#pragma once

#include <raylib.h>

class Laser {
    public:
        // rewrite constructer use modern cpp

        Laser(Vector2 position, int speed);
        ~Laser();
        void Draw();
        void Update();
        void Shoot(Vector2 position);
        bool IsOffScreen();
        bool IsActive();
    private:
        Texture texture;
        Vector2 position;
        int speed;
        bool active;
};