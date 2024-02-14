
#include <string>
#include "raylib.h"
#include "vec2.h"

#include "Game.h"

#include "Laser.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 800;

  Vec2 position(400, 400);

  Vec2 speed(1, 1);

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  Game game;
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    game.HanleInput();
    game.Update();

    game.Draw();
    BeginDrawing();
    DrawFPS(10, 10);

    ClearBackground(BLACK);

    // DrawCircle(position.x, position.y, 20, BLUE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}