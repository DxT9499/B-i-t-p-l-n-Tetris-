#include "Check.h"
#include <string>
#include <SDL.h>
#include "Control.h"
#include "Process.h"
using namespace std;



void control::handle_key(SDL_Event event, int id_shape, bool rotation)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {

            case SDLK_UP: if (id_shape !=5) rotation=true; break;
            case SDLK_LEFT: x_val--; break;
            case SDLK_RIGHT: x_val++; break;
            case SDLK_DOWN: y_val++; break;
        }
    }
}

void control::handle_mouse(SDL_Event event)
{
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            x_mouse=event.motion.x;
            y_mouse=event.motion.y;
        }
    }
}
