//
// Created by grass on 13/11/2022.
//

#include "../include/main_render_functions.h"


void draw_frame(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawLine(renderer, 0, WORLDSIZE_Y - 1, WORLDSIZE_X, WORLDSIZE_Y - 1);
  SDL_RenderDrawLine(renderer, 0, 0, 0, WORLDSIZE_Y);
  SDL_RenderDrawLine(renderer, WORLDSIZE_X - 1, 0, WORLDSIZE_X - 1, WORLDSIZE_Y);
  SDL_RenderDrawLine(renderer, 0, 0, WORLDSIZE_X, 0);
}

void draw_matrix(SDL_Renderer *renderer, world &world) {
  for (int i = 0; i < world.get_matriz().size(); ++i) {
    for ( int j = 0; j < world.get_matriz()[0].size(); ++j) {
      if (world.get_matriz()[i][j].get_state() == '#') {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderDrawPoint(renderer, i, j);
      }
      if (world.get_matriz()[i][j].get_state() == '@') {
        SDL_SetRenderDrawColor(renderer, 255,0,0,255);
        SDL_RenderDrawPoint(renderer, i, j);
      }

      if (world.get_matriz()[i][j].get_state() == 'X') {
        SDL_SetRenderDrawColor(renderer, 0,255,0,255);
        SDL_RenderDrawPoint(renderer, i, j);
      }

      if (world.get_matriz()[i][j].get_state() == '.') {
        SDL_SetRenderDrawColor(renderer, 0,0,255,255);
        SDL_RenderDrawPoint(renderer, i, j);
      }

    }
  }
}

void draw_world(world &w, SDL_Renderer *renderer) {

  for (int i = w.get_player_pos().first - 1; i <= w.get_player_pos().first + 1; ++i) {
    for (int j = w.get_player_pos().second - 1; j <= w.get_player_pos().second + 1; ++j) {
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

void draw_menu(SDL_Renderer *renderer, int estado) {
  SDL_RenderSetLogicalSize(renderer, MENUSIZE_X, MENUSIZE_Y);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer, new SDL_Rect{0, 0, MENUSIZE_X, MENUSIZE_Y});
  SDL_RenderPresent(renderer);


  // Inicializamos el texto
  if (TTF_Init() < 0) {
    std::cout << "Error: " << TTF_GetError() << std::endl;
  }
  TTF_Font* font = TTF_OpenFont("../assets/Font/TrenchThin-aZ1J.ttf", 24);
  if (font == nullptr) {
    std::cout << "Error: " << TTF_GetError() << std::endl;
  }

  // colors
  SDL_Color white = {255, 255, 255};
  SDL_Color red = {255, 0, 0};
  SDL_Color purple = {255, 0, 255};
  SDL_Color orange = {255, 165, 0};
  SDL_Color green = {0, 255, 0};

  std::vector<SDL_Color> colors;

  if(estado == 0)
    colors = {green, white, red};
  else if(estado == 1)
    colors = {white, green, red};
  else if(estado == 2)
    colors = {white, white, green};


  // draw Title

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "PRACTICA 2 IA", orange);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = MENUSIZE_X/2 - MENUSIZE_X/4;
    Message_rect.y = 10;
    Message_rect.w = MENUSIZE_X/2;
    Message_rect.h = 15;
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);


  // draw option 1 inside a box with thin line - Mannhattan Distance

    SDL_Surface* surfaceMessage1 = TTF_RenderText_Solid(font, "Manhattan Distance", colors[0]);
    SDL_Texture* Message1 = SDL_CreateTextureFromSurface(renderer, surfaceMessage1);
    SDL_FreeSurface(surfaceMessage1);
    SDL_Rect Message_rect1;
    Message_rect1.x = MENUSIZE_X/2 - MENUSIZE_X/4;
    Message_rect1.y = 60;
    Message_rect1.w = MENUSIZE_X/2;
    Message_rect1.h = 5;
    SDL_RenderCopy(renderer, Message1, NULL, &Message_rect1);


  // draw option 2 inside a box - Euclidean Distance

    SDL_Surface* surfaceMessage2 = TTF_RenderText_Solid(font, "Euclidean Distance", colors[1]);
    SDL_Texture* Message2 = SDL_CreateTextureFromSurface(renderer, surfaceMessage2);
    SDL_FreeSurface(surfaceMessage2);
    SDL_Rect Message_rect2;

    Message_rect2.x = MENUSIZE_X/2 - MENUSIZE_X/4;
    Message_rect2.y = 70;
    Message_rect2.w = MENUSIZE_X/2;
    Message_rect2.h = 5;
    SDL_RenderCopy(renderer, Message2, NULL, &Message_rect2);


  // draw option 3 quit

    SDL_Surface* surfaceMessage3 = TTF_RenderText_Solid(font, "Quit", colors[2]);
    SDL_Texture* Message3 = SDL_CreateTextureFromSurface(renderer, surfaceMessage3);
    SDL_FreeSurface(surfaceMessage3);
    SDL_Rect Message_rect3;

    Message_rect3.x = MENUSIZE_X/2 - MENUSIZE_X/16;
    Message_rect3.y = 80;
    Message_rect3.w = MENUSIZE_X/10;
    Message_rect3.h = 5;
    SDL_RenderCopy(renderer, Message3, NULL, &Message_rect3);



  // draw bottom text

    SDL_Surface* surfaceMessage4 = TTF_RenderText_Solid(font, "Adrian Grassin Luis - ULL", purple);
    SDL_Texture* Message4 = SDL_CreateTextureFromSurface(renderer, surfaceMessage4);
    SDL_Rect Message_rect4;

    Message_rect4.x = MENUSIZE_X/2 - MENUSIZE_X/4;
    Message_rect4.y = 95;
    Message_rect4.w = MENUSIZE_X/2;
    Message_rect4.h = 4;
    SDL_RenderCopy(renderer, Message4, NULL, &Message_rect4);


  SDL_RenderPresent(renderer);
  SDL_DestroyTexture(Message);
  SDL_DestroyTexture(Message1);
  SDL_DestroyTexture(Message2);
  SDL_DestroyTexture(Message3);
  SDL_DestroyTexture(Message4);
  TTF_CloseFont(font);
  TTF_Quit();
}