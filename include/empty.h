//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__EMPTY_H_
#define IA_GRAPHIC__EMPTY_H_

#include "estado.h"

class Empty_state : public Estado {
 private:
  const char symbol = ' ';

 public:
  char get_symbol() override;
};


#endif //IA_GRAPHIC__EMPTY_H_
