//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__PATH_H_
#define IA_GRAPHIC__PATH_H_

#include "estado.h"

//el camino se genera tal que OoOoOoOoOoOo

class Path_state : public Estado {
 private:
 char symbol;

 public:
  Path_state();
  char get_symbol() override;
};



#endif //IA_GRAPHIC__PATH_H_
