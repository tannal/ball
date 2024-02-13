#include "Game.h"
Game::Game() {
  // ship = SpaceShip();
  obstacles = createObstacles();
}

Game::~Game() {}

void Game::Update() {
  for (auto& laser : ship.lasers) {
    laser.Update();
  }
}

void Game::Draw() {
  ship.Draw();

  for (auto& laser : ship.lasers) {
    laser.Draw();
  }

  for(auto& obstacle: obstacles) {
    obstacle.Draw();
  }

}

void Game::HanleInput() {
  if (IsKeyDown(KEY_RIGHT)) {
    ship.MoveRight();
  } else if (IsKeyDown(KEY_LEFT)) {
    ship.MoveLeft();
  } else if (IsKeyDown(KEY_SPACE)) {
    ship.FireLaser();
  }
}

void Game::DeleteInactiveLasers() {
  for (auto it = ship.lasers.begin(); it != ship.lasers.end();) {
    if (!it->IsActive()) {
      it = ship.lasers.erase(it);
    } else {
      it++;
    }
  }
}

std::vector<Obstacle> Game::createObstacles() {
  std::vector<Obstacle> obstacles;
  int obstacleWidth = Obstacle::grid[0].size() * 3;
  float gap = (GetScreenWidth() - obstacleWidth * 4) / 5;
  for(int i = 0; i < 4; i++) {
    float offsetX = (i + 1) * gap + i * obstacleWidth;
    obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
  }

  return obstacles;
}
