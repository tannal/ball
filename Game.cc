#include "Game.h"

Game::Game() {}

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
