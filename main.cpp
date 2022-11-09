#include <iostream>
#include <random>
#include <SDL.h>
#include <algorithm>
#include "include/world.h"

#define WORLDSIZE_X 100
#define WORLDSIZE_Y 100

void draw_frame(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawLine(renderer, 0, WORLDSIZE_Y - 1, WORLDSIZE_X, WORLDSIZE_Y - 1);
  SDL_RenderDrawLine(renderer, 0, 0, 0, WORLDSIZE_Y);
  SDL_RenderDrawLine(renderer, WORLDSIZE_X - 1, 0, WORLDSIZE_X - 1, WORLDSIZE_Y);
  SDL_RenderDrawLine(renderer, 0, 0, WORLDSIZE_X, 0);
}

void draw_world(world &w, SDL_Renderer *renderer) {

  for (int i = w.get_player_pos().first - 1; i < w.get_player_pos().first + 1; ++i) {
    for (int j = w.get_player_pos().second - 1; j < w.get_player_pos().second + 1; ++j) {
      if (w.get_matriz()[i][j].get_state() == 'O') {
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // yellow
        SDL_RenderDrawPoint(renderer, i, j);
      }
    }
  }

  SDL_SetRenderDrawColor(renderer, rand() + 1, rand() + 1, rand() + 1, 255);
  SDL_RenderDrawPoint(renderer, w.get_end_pos().first, w.get_end_pos().second);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderDrawPoint(renderer, w.get_player_pos().first, w.get_player_pos().second);
  SDL_RenderPresent(renderer);

}

int main(int argc, char *argv[]) {

  // inicializamos SDL
  //

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  window = SDL_CreateWindow("Select sort",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            100 * 10,
                            100 * 10,
                            0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetLogicalSize(renderer, WORLDSIZE_X, WORLDSIZE_Y);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);


  // inicializamos el mundo
  //

  world w(WORLDSIZE_X, WORLDSIZE_Y);
  w.set_player();
  w.set_end();

  int timestop = 15;
  if (WORLDSIZE_X > 500 || WORLDSIZE_Y > 500) {
    timestop = 5;
  }

  draw_frame(renderer);


  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }
    w.getnexstate();
    draw_world(w, renderer);
    SDL_Delay(timestop);


    if (w.get_player_pos() == w.get_end_pos()) {
      quit = true;
    }
  }

  std::cout << "PATH FOUND" << std::endl;
  SDL_Delay(1000);


  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

