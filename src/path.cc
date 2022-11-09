//
// Created by Adri on 02/11/2022.
//

#include "../include/path.h"

char Path_state::get_symbol() {
  return symbol;
}
Path_state::Path_state() {
  srand(time(nullptr));
  if(rand() % 2 == 0) {
    symbol = 'O';
  } else {
    symbol = 'o';
  }

}
