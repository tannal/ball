
#include "raylib.h"
#include "vec2.h"
#include <string>

#include "Game.h"

#include "Laser.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    Vec2 position(400, 400);

    Vec2 speed(1, 1);


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    Game game;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // handle arrow keys
        // if (IsKeyDown(KEY_RIGHT))
        // {
        //     speed.x = 10;
        // }
        // else if (IsKeyDown(KEY_LEFT))
        // {
        //     speed.x = -10;
        // }
        // else if (IsKeyDown(KEY_UP))
        // {
        //     speed.y = -10;
        // }
        // else if (IsKeyDown(KEY_DOWN))
        // {
        //     speed.y = 10;
        // }
        // else
        // {
        //     speed.x = 0;
        //     speed.y = 0;
        // }

        // position += speed;
        game.HanleInput();

        game.Update();

        BeginDrawing();

        DrawFPS(10, 10);
        // convert position and speed to string
        std::string positionStr = "Position: " + position.to_string();
        std::string speedStr = "Speed: " + speed.to_string();
        // draw text
        DrawText(positionStr.c_str(), 10, 800 - 40, 20, RED);
        DrawText(speedStr.c_str(), 10, 800 - 60, 20, RED);
        
        game.Draw();
        

        ClearBackground(BLACK);

        // DrawCircle(position.x, position.y, 20, BLUE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();
    return 0;
}