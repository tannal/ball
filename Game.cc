#include "Game.h"

Game::Game() {
  // ship = SpaceShip();
  obstacles = createObstacles();
  aliens = createAliens();
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

  for(auto& alien: aliens) {
    alien.Draw();
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

std::vector<Alien> Game::createAliens() {
  std::vector<Alien> aliens;
  for(int row = 0; row < 5; row++) {
    for(int column = 0; column < 11; column++) {
      float x = column * 55;
      float y = row * 55;

      if(row == 0) {
        aliens.push_back(Alien({x, y}, 3));
        continue;
      }else if(row < 3) {
        aliens.push_back(Alien({x, y}, 2));
        continue;
      }


      aliens.push_back(Alien({x, y}, 1));
    }
  }

  return aliens;
}
