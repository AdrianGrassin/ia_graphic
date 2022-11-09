//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__OBSTACLE_H_
#define IA_GRAPHIC__OBSTACLE_H_

#include "estado.h"

class Obstacle_state : public Estado {
 private:
  const char symbol = '#';

 public:
  char get_symbol() override;

};

#endif //IA_GRAPHIC__OBSTACLE_H_
