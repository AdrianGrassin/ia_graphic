//
// Created by Adri on 02/11/2022.
//

#include "../include/celda.h"
void Celda::set_state(Estado *estado) {
  estado_ = estado;
}
char Celda::get_state() const {
  return estado_->get_symbol();
}
