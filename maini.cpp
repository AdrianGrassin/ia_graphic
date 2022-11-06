#include <iostream>
#include <SDL.h>
#include "include/sdl_functions_own.h"

SDL_Window *globals::window = nullptr;
SDL_Surface *globals::screenSurface = nullptr;
SDL_Surface *globals::gStretchedSurface = nullptr;


int main(int argc, char *argv[]) {

  if (!init()) {
    std::cout << "Fallo la inicialización" << std::endl;
  } else {
    if (!loadMedia()) {
      std::cout << "Fallo la carga de la imagen" << std::endl;
    } else {

      bool quit = false;
      SDL_Event e;

      while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
          if (e.type == SDL_QUIT) {
            quit = true;
          }
          // codigo para dibujar
          SDL_Rect stretchRect;
          stretchRect.x = 0;
          stretchRect.y = 0;
          stretchRect.w = globals::SCREEN_WIDTH;
          stretchRect.h = globals::SCREEN_HEIGHT;
          SDL_BlitScaled(globals::gStretchedSurface, NULL, globals::screenSurface, &stretchRect);


          SDL_UpdateWindowSurface( globals::window );
          }

        }
      }
    close();
    }
  return 0;
}

