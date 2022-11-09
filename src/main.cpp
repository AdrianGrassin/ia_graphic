#include <iostream>
#include "../include/world.h"
#include <unistd.h>
#include <fstream>

int main() {
  world w(30, 30);
  w.set_player();
  w.set_end();
  while (w.get_player_pos() != w.get_end_pos()) {
    usleep(2000);
    system("cls");
    std::cout << w;
    w.getnexstate();
  }
    std::cout << "Has llegado al final" << std::endl;
  system("pause");

  std::ofstream myfile;
  myfile.open("ouput.txt");
  myfile << w;
  myfile.close();

  //system("pause");
  return 0;

}
