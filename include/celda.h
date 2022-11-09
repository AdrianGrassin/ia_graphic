//
// Created by Adri on 02/11/2022.
//

#ifndef IA_GRAPHIC__CELDA_H_
#define IA_GRAPHIC__CELDA_H_

#include "estado.h"

class Celda {
 private:
  Estado *estado_;

 public:
  void set_state(Estado *estado);
  char get_state() const;

};

#endif //IA_GRAPHIC__CELDA_H_
