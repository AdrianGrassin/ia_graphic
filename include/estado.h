//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__ESTADO_H_
#define IA_GRAPHIC__ESTADO_H_

#include <iostream>

class Estado {

 public:
  virtual char get_symbol() = 0;

  std::ostream& operator<<(std::ostream& os) {
    os << get_symbol();
    return os;
  }
};

#endif //IA_GRAPHIC__ESTADO_H_
