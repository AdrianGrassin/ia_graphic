//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__END_H_
#define IA_GRAPHIC__END_H_

#include "estado.h"

class End_state : public Estado {
 private:
  const char symbol = 'X';

 public:
  char get_symbol() override;
};


#endif //IA_GRAPHIC__END_H_
