//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__WORLD_H_
#define IA_GRAPHIC__WORLD_H_

#include <vector>
#include "celda.h"
#include <iostream>
#include "obstacle.h"
#include "path.h"
#include "empty.h"
#include "player.h"
#include <ctime>
#include <cstdlib>
#include "end.h"
#include "Visitado_State.h"

class world {
 private:
  std::vector<std::vector<Celda>> matriz_;
  std::pair<int, int> player_pos_;
  std::pair<int, int> end_pos_;

 public:
   world(int size_i, int size_x);
  void set_player();
  void set_end();
  void getnexstate();
  void setAstarpath();
  std::vector<std::vector<Celda>> &get_matriz();

  std::pair<int, int> get_player_pos() const;
  std::pair<int, int> get_end_pos() const;

  friend std::ostream &operator<<(std::ostream &os, const world &world);




};

#endif //IA_GRAPHIC__WORLD_H_
