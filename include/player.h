//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__PLAYER_H_
#define IA_GRAPHIC__PLAYER_H_

#include "estado.h"

class Player_state : public Estado {
 private:
  const char symbol = '@';

 public:
  char get_symbol() override;
};


#endif //IA_GRAPHIC__PLAYER_H_
