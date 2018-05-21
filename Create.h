#ifndef CREATE_H_INCLUDED
#define CREAT_H_INCLUDED

#include <SDL.h>
#include "Perform.h"

bool Init(SDL_Renderer** renderer, SDL_Window* window);
void Clean(SDL_Window** window,SDL_Renderer** renderer,SDL_Texture* color_block[TOTAL]);
void pause(SDL_Renderer* renderer,SDL_Event event);
void run(SDL_Renderer* renderer);
void playGame(SDL_Renderer* renderer);

#endif // CREATE_H_INCLUDED
