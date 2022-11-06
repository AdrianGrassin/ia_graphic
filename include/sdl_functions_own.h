//
// Created by grass on 05/11/2022.
//

#ifndef MAIN_CPP__SDL_FUNCTIONS_OWN_H_
#define MAIN_CPP__SDL_FUNCTIONS_OWN_H_

#include <iostream>
#include <SDL.h>

enum KeyPressSurfaces {
  KEY_PRESS_SURFACE_DEFAULT,
  KEY_PRESS_SURFACE_UP,
  KEY_PRESS_SURFACE_DOWN,
  KEY_PRESS_SURFACE_LEFT,
  KEY_PRESS_SURFACE_RIGHT,
  KEY_PRESS_SURFACE_TOTAL
};



/************************ SDL GLOBAL VARIABLES ***************************/
namespace globals {
static const int SCREEN_HEIGHT = 480;
static const int SCREEN_WIDTH = 640;

// Puntero a la ventana que se va a crear
extern SDL_Window *window;

// Puntero al render
extern SDL_Surface *screenSurface;

// Puntero a la imagen que se va a cargar
extern SDL_Surface *helloWorld;

// Vector de imagenes para las teclas
extern SDL_Surface *gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

// Imagen actual
extern SDL_Surface *gCurrentSurface;
}

/******************************* Definiciones *******************************/


bool init();

bool loadMedia();

SDL_Surface* loadSurface(std::string path);

void close();

#endif //MAIN_CPP__SDL_FUNCTIONS_OWN_H_
