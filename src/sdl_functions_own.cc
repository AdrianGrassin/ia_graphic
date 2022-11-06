//
// Created by grass on 05/11/2022.
//

#include "../include/sdl_functions_own.h"


/******************************* Funciones *******************************/

bool init() {
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }
  else
  {
    //Create window
    globals::window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if( globals::window == NULL )
    {
      std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
      success = false;
    }
    else
    {
      //Initialize PNG loading
      int imgFlags = IMG_INIT_PNG;
      if( !( IMG_Init( imgFlags ) & imgFlags ) )
      {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        success = false;
      }
      else
      {
        //Get window surface
        globals::screenSurface = SDL_GetWindowSurface( globals::window );
      }
    }
  }

  return success;
}


bool loadMedia()
{
  //Loading success flag
  bool success = true;

  //Load PNG surface
  globals::gStretchedSurface = loadSurface( "../assets/flalindisimaprechocha.png" );
  if( globals::gStretchedSurface == NULL )
  {
    std::cout << "Failed to load PNG image!" << std::endl;
    success = false;
  }

  return success;
}

SDL_Surface* loadSurface( std::string path )
{
  //The final optimized image
  SDL_Surface* optimizedSurface = NULL;

  //Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  if( loadedSurface == NULL )
  {
    std::cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
  }
  else
  {
    //Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface( loadedSurface, globals::screenSurface->format, 0 );
    if( optimizedSurface == NULL )
    {
      std::cout << "Unable to optimize image " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
  }

  return optimizedSurface;
}

void close()
{
  //Deallocate surface
  SDL_FreeSurface( globals::gStretchedSurface );
  globals::gStretchedSurface = NULL;

  //Destroy window
  SDL_DestroyWindow( globals::window );
  globals::window = NULL;

  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}