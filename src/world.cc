//
// Created by Adri on 02/11/2022.
//

#include "../include/world.h"

world::world(int size_i, int size_x) {
  std::srand(time(nullptr));

  matriz_.resize(size_i);
  for (int i = 0; i < size_i; ++i) {
    matriz_[i].resize(size_x);
  }

  // Seteamos los obstaculos

  for (int i = 0; i < size_i; ++i) {
    for (int j = 0; j < size_x; ++j) {
      if (i == 0 || j == 0 || i == size_i - 1 || j == size_x - 1) {
        Estado *stateAux = new Obstacle_state();
        matriz_[i][j].set_state(stateAux);
      } else {
        Estado *stateAux = new Empty_state();
        matriz_[i][j].set_state(stateAux);
      }
    }
  }

}
std::ostream &operator<<(std::ostream &os, const world &world) {

  for (const auto &i : world.matriz_) {
    for (auto j : i) {
      os << j.get_state();
    }
    os << std::endl;
  }
  return os;
}

void world::set_player() {
  Estado *stateAux = new Player_state();
  int x = 0, y = 0;
  while (matriz_[x][y].get_state() == '#') {
    x++;
    y++;
  }
  matriz_[x][y].set_state(stateAux);
  player_pos_.first = x;
  player_pos_.second = y;

}
void world::getnexstate() {
  int x = player_pos_.first;
  int y = player_pos_.second;


  // mover el player hacia el end
  if (x < end_pos_.first && matriz_[x + 1][y].get_state() != '#') {
    matriz_[x][y].set_state(new Path_state());
    x++;
    matriz_[x][y].set_state(new Player_state());
    player_pos_.first = x;
  } else if (x > end_pos_.first && matriz_[x - 1][y].get_state() != '#') {
    matriz_[x][y].set_state(new Path_state());
    x--;
    matriz_[x][y].set_state(new Player_state());
    player_pos_.first = x;
  } else if (y < end_pos_.second && matriz_[x][y + 1].get_state() != '#') {
    matriz_[x][y].set_state(new Path_state());
    y++;
    matriz_[x][y].set_state(new Player_state());
    player_pos_.second = y;
  } else if (y > end_pos_.second && matriz_[x][y - 1].get_state() != '#') {
    matriz_[x][y].set_state(new Path_state());
    y--;
    matriz_[x][y].set_state(new Player_state());
    player_pos_.second = y;
  }

}

void world::set_end() {
  srand(time(nullptr));

  int x = rand() % matriz_.size() - 1;
  int y = rand() % matriz_[0].size() - 1;
  matriz_[x][y].set_state(new End_state());

  end_pos_.first = x;
  end_pos_.second = y;

}
std::pair<int, int> world::get_player_pos() const {
  return player_pos_;
}
std::pair<int, int> world::get_end_pos() const {
  return end_pos_;
}
