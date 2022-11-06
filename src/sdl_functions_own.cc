//
// Created by grass on 05/11/2022.
//

#include "../include/sdl_functions_own.h"




/******************************* Funciones *******************************/

bool init() {
  // flag de inicialización
  bool success = true;

  // Iniciamos SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL no se pudo inicializar ! SDL_Error: " << SDL_GetError() << std::endl;
    success = false;
  } else {
    // Crea la ventana en la que se va a renderizar el código
    globals::window = SDL_CreateWindow("SDL - INITIALIZED",
                                       SDL_WINDOWPOS_UNDEFINED,
                                       SDL_WINDOWPOS_UNDEFINED,
                                       globals::SCREEN_WIDTH,
                                       globals::SCREEN_HEIGHT,
                                       SDL_WINDOW_SHOWN);

    if (globals::window == nullptr) {
      std::cout << "La ventana no pudo ser creada ! SDL_Error: " << SDL_GetError() << std::endl;
      success = false;
    } else {
      // Obtenemos el surface de la ventana
      globals::screenSurface = SDL_GetWindowSurface(globals::window);
    }
  }
  return success;
}

bool loadMedia() {
  bool success = true;

    // Cargamos la imagen
    globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("../assets/press.bmp");
    if (globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr) {
      std::cout << "No se pudo cargar la imagen por defecto" << std::endl;
      success = false;
    }

    // Cargamos la imagen para la tecla arriba
    globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("../assets/up.bmp");
    if (globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == nullptr) {
      std::cout << "No se pudo cargar la imagen para la tecla arriba" << std::endl;
      success = false;
    }

    // Cargamos la imagen para la tecla abajo
    globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("../assets/down.bmp");
    if (globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr) {
      std::cout << "No se pudo cargar la imagen para la tecla abajo" << std::endl;
      success = false;
    }

    // Cargamos la imagen para la tecla izquierda
    globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("../assets/left.bmp");
    if (globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr) {
      std::cout << "No se pudo cargar la imagen para la tecla izquierda" << std::endl;
      success = false;
    }

    // Cargamos la imagen para la tecla derecha
    globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("../assets/right.bmp");
    if (globals::gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr) {
      std::cout << "No se pudo cargar la imagen para la tecla derecha" << std::endl;
      success = false;
    }

    return success;

}

SDL_Surface* loadSurface(std::string path) {
  // Cargamos la imagen
  SDL_Surface *loadedSurface = SDL_LoadBMP(path.c_str());

  if (loadedSurface == nullptr) {
    std::cout << "No se pudo cargar la imagen ! SDL_Error: " << SDL_GetError() << std::endl;
  }

  return loadedSurface;
}

void close() {
  // Liberamos la imagen
  SDL_FreeSurface(globals::helloWorld);
  globals::helloWorld = nullptr;

  // Destruimos la ventana
  SDL_DestroyWindow(globals::window);
  globals::window = nullptr;

  // Quitamos SDL
  SDL_Quit();
}