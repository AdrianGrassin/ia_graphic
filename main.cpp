#include <iostream>
#include <SDL.h>
#include "include/sdl_functions_own.h"

SDL_Window *globals::window = nullptr;
SDL_Surface *globals::screenSurface = nullptr;
SDL_Surface *globals::helloWorld = nullptr;
SDL_Surface *globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface *globals::gCurrentSurface = nullptr;



int main(int argc, char *argv[]) {

  if (!init()) {
    std::cout << "Fallo la inicialización" << std::endl;
  } else {
    if (!loadMedia()) {
      std::cout << "Fallo la carga de la imagen" << std::endl;
    } else {

      bool quit = false;
      SDL_Event e;

      // Aplicamos la imagen actual por defecto
      globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
      SDL_BlitSurface( globals::gCurrentSurface, nullptr, globals::screenSurface, nullptr );
      SDL_UpdateWindowSurface( globals::window );

      while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
          if (e.type == SDL_QUIT) {
            quit = true;
          }
          // Cambiamos la imagen actual si se presiona una tecla
          else if (e.type == SDL_KEYDOWN) { // keydown - presionar tecla
            switch (e.key.keysym.sym) {
              case SDLK_UP:
                globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
                break;
              case SDLK_DOWN:
                globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                break;
              case SDLK_LEFT:
                globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                break;
              case SDLK_RIGHT:
                globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                break;
              default:
                globals::gCurrentSurface = globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                break;
            }
            SDL_BlitSurface( globals::gCurrentSurface, nullptr, globals::screenSurface, nullptr );
            SDL_UpdateWindowSurface( globals::window );
          }

        }
      }
    }
  }

  return 0;
}

