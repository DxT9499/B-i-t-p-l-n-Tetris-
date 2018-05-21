#include <iostream>
#include <SDL.h>
#include <string>
#include <ctime>
#include "Create.h"

using namespace std;

int main(int argc, char* args[])
{
    srand(time(NULL));
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;
    if (!Init(&renderer,window))
    {
        cout << "Can't INIT Window Screen. ";
        return 0;
    }
    else if (!loadBlockAndNumber(renderer))
            {
            cout << "Can't load BLOCK. ";
            }
            else
            {
            run(renderer);
            }
    Clean(&window,&renderer,colorBlock);
    return 0;
}


