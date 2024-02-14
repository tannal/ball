#pragma once

#include <raylib.h>

class Alien {
    public:
        Alien(Vector2 position, int type);
        void Update();
        void Draw();
        int GetType();
        Texture2D image;

        int type;

        Vector2 position;

    private:

};