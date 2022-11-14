#include <iostream>
#include "include/main_render_functions.h"

int main(int argc, char *argv[]) {

  // inicializamos SDL
  //

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  window = SDL_CreateWindow("Select sort",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            1080,
                            720,
                            0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_RenderSetLogicalSize(renderer, 100, 100);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);


  // inicializamos el mundo
  //


  int timestop = 45;

  if (WORLDSIZE_X > 500 || WORLDSIZE_Y > 500) {
    timestop = 15;
  }

  bool menu = true;
  bool game = false;
  bool end = false;
  int estado = 0;

  while (!end) {
    draw_menu(renderer, estado);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        end = false;
      }
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_UP:
            if (estado == 1 || estado == 2) {
              estado--;
            }
            break;
          case SDLK_DOWN:
            if (estado == 0 || estado == 1) {
              estado++;
            }
            break;
          case SDLK_RETURN:
            if (estado == 0) {
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
              SDL_RenderClear(renderer);
              SDL_RenderSetLogicalSize(renderer, WORLDSIZE_X, WORLDSIZE_Y);

              world w(WORLDSIZE_X, WORLDSIZE_Y);
              w.set_player();
              w.set_end();
              w.setAstarpath_mannhattan();
              draw_frame(renderer);

              bool quit = false;
              while (!quit) {
                w.getnexstate();
                draw_world(w, renderer);
                SDL_Delay(timestop);

                if (w.get_player_pos() == w.get_end_pos()) {
                  quit = true;
                }

                SDL_Event inside_event;
                SDL_PollEvent(&inside_event);
                if (inside_event.type == SDL_QUIT) {
                  quit = true;
                }
              }

              SDL_RenderSetLogicalSize(renderer, MENUSIZE_X, MENUSIZE_Y);
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
              SDL_RenderClear(renderer);
            }
            if (estado == 1) {
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
              SDL_RenderClear(renderer);
              SDL_RenderSetLogicalSize(renderer, WORLDSIZE_X, WORLDSIZE_Y);

              world w(WORLDSIZE_X, WORLDSIZE_Y);

              w.set_player();
              w.set_end();
              w.setAstarpath_euclidean();

              bool quit = false;
              draw_frame(renderer);
              while (!quit) {
                w.getnexstate();
                draw_world(w, renderer);
                SDL_Delay(timestop);

                if (w.get_player_pos() == w.get_end_pos()) {
                  quit = true;
                }

                SDL_Event inside_event;
                SDL_PollEvent(&inside_event);
                if (inside_event.type == SDL_QUIT) {
                  quit = true;
                }
              }

              SDL_RenderSetLogicalSize(renderer, MENUSIZE_X, MENUSIZE_Y);
              SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
              SDL_RenderClear(renderer);
            }
            if (estado == 2) {
              end = true;

              SDL_DestroyRenderer(renderer);
              SDL_DestroyWindow(window);
              SDL_Quit();
              return 0;
            }
            break;
        }
      }
    }
  }

  return 0;
}
