//
// Created by Adri on 02/11/2022.
//

#include <queue>
#include <unordered_set>
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
    int i = std::rand() % (matriz_.size() - 2) + 1;
    int j = std::rand() % (matriz_[0].size() - 2) + 1;
    player_pos_ = std::make_pair(i, j);
}

void world::getnexstate() {
  int x = player_pos_.first;
  int y = player_pos_.second;


  // mover hacia la celda vecina que tenga el simbolo .
  // siempre hay una celda con el simbolo .

    if (matriz_[x][y - 1].get_state() == '.') {
        matriz_[x][y].set_state(new Path_state());
        matriz_[x][y - 1].set_state(new Player_state());
        player_pos_ = std::make_pair(x, y - 1);
    } else if (matriz_[x][y + 1].get_state() == '.') {
        matriz_[x][y].set_state(new Path_state());
        matriz_[x][y + 1].set_state(new Player_state());
        player_pos_ = std::make_pair(x, y + 1);
    } else if (matriz_[x - 1][y].get_state() == '.') {
        matriz_[x][y].set_state(new Path_state());
        matriz_[x - 1][y].set_state(new Player_state());
        player_pos_ = std::make_pair(x - 1, y);
    } else if (matriz_[x + 1][y].get_state() == '.') {
        matriz_[x][y].set_state(new Path_state());
        matriz_[x + 1][y].set_state(new Player_state());
        player_pos_ = std::make_pair(x + 1, y);
    }




}



void world::set_end() {
  srand(time(nullptr));

  int x = rand() % matriz_.size() - 2;
  int y = rand() % matriz_[0].size() - 2;
  matriz_[x + 1][y + 1].set_state(new End_state());

  end_pos_.first = x + 1;
  end_pos_.second = y + 1;

}
std::pair<int, int> world::get_player_pos() const {
  return player_pos_;
}
std::pair<int, int> world::get_end_pos() const {
  return end_pos_;
}
std::vector<std::vector<Celda>> &world::get_matriz() {
  return matriz_;
}
void world::setAstarpath() {


  // matriz de heuristica de manhattan

  std::vector<std::vector<int>> matriz_costos;
  matriz_costos.resize(matriz_.size());

  for (int i = 0; i < matriz_.size(); ++i) {
    matriz_costos[i].resize(matriz_[0].size());
  }

  for (int i = 0; i < matriz_.size(); ++i) {
    for (int j = 0; j < matriz_[0].size(); ++j) {
      matriz_costos[i][j] = abs(i - end_pos_.first) + abs(j - end_pos_.second);
    }
  }

  // calculo del camino minimo

  std::pair<int, int> actual = player_pos_;
  std::pair<int, int> next = player_pos_;

  while (actual != end_pos_) {
    for (int i = actual.first - 1; i <= actual.first + 1; i++) {
      for (int j = actual.second - 1; j <= actual.second + 1; j++) {
        if (i == actual.first || j == actual.second && matriz_[i][j].get_state() != '#') {
          if (matriz_costos[i][j] < matriz_costos[next.first][next.second]) {
            next.first = i;
            next.second = j;
          }
        }
      }
    }
    std::cout << "Visited: " << next.first << " " << next.second << std::endl;
    matriz_[next.first][next.second].set_state(new Visitado_State());
    actual = next;
  }

}










