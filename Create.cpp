#include "Create.h"
#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
#include "Check.h"
#include "Process.h"

using namespace std;

bool Init(SDL_Renderer** renderer, SDL_Window* window)
{
    bool success = true;
    window = SDL_CreateWindow("TETRIS", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH+400,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if ( window == NULL )
    {
        cout << "Window could not be created. Error: \n" << SDL_GetError();
        success = false;
    }
    else
    {
        *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if (*renderer == NULL)
        {
            cout << "Renderer could not be created. Error: \n" << SDL_GetError();
            success = false;
        }
        else
        SDL_SetRenderDrawColor(*renderer,0,0,0,0);

    }
	return success;
}

void Clean(SDL_Window** window,SDL_Renderer** renderer,SDL_Texture* colorBlock[TOTAL])
{
    SDL_DestroyWindow(*window);
    SDL_DestroyRenderer(*renderer);
    for (int i=0;i<TOTAL;i++)
    {
        SDL_DestroyTexture(colorBlock[i]);
        colorBlock[i] = NULL;
    }
    Mix_CloseAudio();
    *window = NULL;
    *renderer = NULL;
    SDL_Quit();
}

void pause(SDL_Renderer* renderer,SDL_Event event)
{
    bool pause = true;
                    Mix_PauseMusic();
                    SDL_RenderPresent(renderer);
                    while(pause)
                        {
                        if(SDL_WaitEvent(&event))
                            if(event.type == SDL_KEYDOWN)
                                if(event.key.keysym.sym == SDLK_SPACE)
                                    {
                                        pause = false;
                                        SDL_RenderPresent(renderer);
                                        SDL_Delay(100);
                                        Mix_ResumeMusic();
                                    }
                        }
}

void run(SDL_Renderer* renderer)
{
    if(start(renderer) == play_game)
    {
        playGame(renderer);
    }

}

void playGame(SDL_Renderer* renderer)
{
    SDL_Event event;
    int score = 0;
    int board[BOARD_HEIGHT][BOARD_WIDTH] = {0};
    int numScore[5]={0};
    bool quit = false;
    Mix_Chunk* chunk = NULL;
    Mix_Music* music = NULL;
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) == -1) cout << "music error"<<endl;
    chunk = Mix_LoadWAV("yes.wav");
    if(chunk == NULL) cout << Mix_GetError();
    music = Mix_LoadMUS("backmusic.wav");
    if(music == NULL) cout << Mix_GetError();
    process play;
    play.createNext();
    play.create();
    play.createNext();
    while (!quit)
    {
        if(!Mix_PlayingMusic())
            Mix_PlayMusic(music,0);
            while (SDL_PollEvent(&event)!=0)
            {
                if(event.type == SDL_KEYDOWN)
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    pause(renderer,event);
                }
                if (event.type == SDL_QUIT) quit = true;
                play.handleKey(event);
            }
            play.handleMoveAndRotate(board);
            play.setBoard(board);
            checkBoard(board, score, quit, numScore,chunk,renderer);
            showBack(renderer);
            showBoard(renderer,board);
            play.showNow(renderer);
            play.showNext(renderer);
            showScore(numScore,renderer);
            SDL_RenderPresent(renderer);
    }
}


