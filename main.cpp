#include <iostream>
#include <SDL.h>
#include "include/sdl_functions_own.h"

SDL_Window *globals::window = nullptr;
SDL_Surface *globals::screenSurface = nullptr;
SDL_Texture *globals::gTexture = nullptr;
SDL_Renderer *globals::renderer = nullptr;

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


          SDL_Rect topLeftViewport;
          topLeftViewport.x = 0;
          topLeftViewport.y = 0;
          topLeftViewport.w = globals::SCREEN_WIDTH / 2;
          topLeftViewport.h = globals::SCREEN_HEIGHT / 2;
          SDL_RenderSetViewport( globals::renderer, &topLeftViewport );

          //Render texture to screen
          SDL_RenderCopy( globals::renderer, globals::gTexture, NULL, NULL );

          SDL_Rect bottomViewport;
          bottomViewport.x = 0;
          bottomViewport.y = globals::SCREEN_HEIGHT / 2;
          bottomViewport.w = globals::SCREEN_WIDTH;
          bottomViewport.h = globals::SCREEN_HEIGHT / 2;
          SDL_RenderSetViewport( globals::renderer, &bottomViewport );

          //Render texture to screen
          SDL_RenderCopy( globals::renderer, globals::gTexture, NULL, NULL );

          // render top right viewport
          SDL_Rect topRightViewport;
          topRightViewport.x = globals::SCREEN_WIDTH / 2;
          topRightViewport.y = 0;
          topRightViewport.w = globals::SCREEN_WIDTH / 2;
          topRightViewport.h = globals::SCREEN_HEIGHT / 2;

          SDL_RenderSetViewport( globals::renderer, &topRightViewport );
          SDL_RenderCopy( globals::renderer, globals::gTexture, NULL, NULL );

          SDL_RenderPresent(globals::renderer);

          }
        }
      }
    close();
    }
  return 0;
}

