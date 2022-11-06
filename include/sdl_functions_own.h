//
// Created by grass on 05/11/2022.
//

#ifndef MAIN_CPP__SDL_FUNCTIONS_OWN_H_
#define MAIN_CPP__SDL_FUNCTIONS_OWN_H_

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

/************************ SDL GLOBAL VARIABLES ***************************/
namespace globals {

static const int SCREEN_HEIGHT = 720;
static const int SCREEN_WIDTH = 1080;

// Puntero a la ventana que se va a crear
extern SDL_Window *window;

// Puntero al render
extern SDL_Surface *screenSurface;

// Imagen actual
extern SDL_Surface* gStretchedSurface;
}

/******************************* Definiciones *******************************/


bool init();

bool loadMedia();

SDL_Surface* loadSurface(std::string path);

void close();

#endif //MAIN_CPP__SDL_FUNCTIONS_OWN_H_
