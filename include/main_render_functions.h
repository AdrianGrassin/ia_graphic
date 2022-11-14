//
// Created by grass on 13/11/2022.
//

#ifndef MAIN_CPP_INCLUDE_MAIN_RENDER_FUNCTIONS_H_
#define MAIN_CPP_INCLUDE_MAIN_RENDER_FUNCTIONS_H_

#define MENUSIZE_X 100
#define MENUSIZE_Y 100

#define WORLDSIZE_X 300
#define WORLDSIZE_Y 300


#include <SDL.h>
#include <algorithm>
#include <random>
#include "world.h"
#include <SDL_ttf.h>


void draw_frame(SDL_Renderer *renderer);

void draw_matrix(SDL_Renderer *renderer, world &world);

void draw_world(world &w, SDL_Renderer *renderer);

void draw_menu(SDL_Renderer *renderer, int estado);


#endif //MAIN_CPP_INCLUDE_MAIN_RENDER_FUNCTIONS_H_
