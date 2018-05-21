#include <iostream>
#include "Perform.h"
#include <string>
#include <SDL.h>
#include <fstream>

using namespace std;

SDL_Texture* colorBlock[TOTAL] = {NULL};
SDL_Texture* BGR;
SDL_Texture* number[11] = {NULL};

//load và gắn giá trị cho các viên gạch,số
bool loadBlockAndNumber(SDL_Renderer* renderer)
{
    bool success = true;
    colorBlock[RED] = loadTexture(renderer,"pic/red.bmp");
    if (colorBlock[RED] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[BLUEE] = loadTexture(renderer,"pic/bluee.bmp");
    if (colorBlock[BLUEE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[YELLOW] = loadTexture(renderer,"pic/yellow.bmp");
    if (colorBlock[YELLOW] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[PURPLE] = loadTexture(renderer,"pic/purple.bmp");
    if (colorBlock[PURPLE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[GREEN] = loadTexture(renderer,"pic/green.bmp");
    if (colorBlock[GREEN] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[BLUE] = loadTexture(renderer,"pic/blue.bmp");
    if (colorBlock[BLUE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    colorBlock[ORANGE] = loadTexture(renderer,"pic/orange.bmp");
    if (colorBlock[ORANGE] == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    BGR = loadTexture(renderer,"pic/background.bmp");
    if(BGR == NULL)
    {
        cout << "Unable to render IMG. SDL Error: \n" << SDL_GetError();
    }
    number[0] = loadTexture(renderer,"pic/00.bmp");
    if(number[0] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[1] = loadTexture(renderer,"pic/01.bmp");
    if(number[1] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[2] = loadTexture(renderer,"pic/02.bmp");
    if(number[2] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[3] = loadTexture(renderer,"pic/03.bmp");
    if(number[3] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[4] = loadTexture(renderer,"pic/04.bmp");
    if(number[4] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[5] = loadTexture(renderer,"pic/05.bmp");
    if(number[5] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[6] = loadTexture(renderer,"pic/06.bmp");
    if(number[6] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[7] = loadTexture(renderer,"pic/07.bmp");
    if(number[7] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[8] = loadTexture(renderer,"pic/08.bmp");
    if(number[8] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[9] = loadTexture(renderer,"pic/09.bmp");
    if(number[9] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    number[10] = loadTexture(renderer,"pic/scoreboard.bmp");
    if(number[10] == NULL)
    {
        cout << "Unable to render NUM. SDL Error: \n" << SDL_GetError();
        success = false;
    }
    return success;
}
//Hàm load ảnh
SDL_Texture* loadTexture(SDL_Renderer* renderer,string path)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL)
    {
        cout << "Unable to load image. Error: \n " << SDL_GetError();
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << path << " Error: \n" << SDL_GetError();
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
//Hiển thị bảng chứa các viên gạch
void showBoard(SDL_Renderer* renderer,int board[BOARD_HEIGHT][BOARD_WIDTH])
{

    for (int i=0;i<BOARD_HEIGHT;i++)
        for (int j=0;j<BOARD_WIDTH;j++)
        {
            SDL_Rect rectTemp;
            rectTemp.w = BLOCK_SIZE;
            rectTemp.h = BLOCK_SIZE;
            rectTemp.x = j*BLOCK_SIZE;
            rectTemp.y = i*BLOCK_SIZE;
            SDL_RenderCopy(renderer,colorBlock[board[i][j]],NULL,&rectTemp);
        }

}

//In ra bảng điểm số
void showScore(int numScore[5] , SDL_Renderer* renderer)
{
    SDL_Rect scoreRect;
    SDL_Rect scoreBoardRect;
    scoreRect.h = 60;
    scoreRect.w = 30;
    scoreRect.x = 525;
    scoreRect.y = 495;
    scoreBoardRect.h = SCORE_BOARD_HEIGHT;
    scoreBoardRect.w = SCORE_BOARD_WIDTH;
    scoreBoardRect.x = 450;
    scoreBoardRect.y = 440;
    SDL_RenderCopy(renderer,number[10],NULL,&scoreBoardRect);
    for(int i = 0 ; i <= 4 ; i++)
    {
        SDL_RenderCopy(renderer,number[numScore[i]],NULL,&scoreRect);
        scoreRect.x+=30;
    }
}
//In background
void showBack(SDL_Renderer* renderer)
{
    SDL_Rect fullRect;
    fullRect.x = 0;
    fullRect.y = 0;
    fullRect.h = SCREEN_HEIGHT;
    fullRect.w = SCREEN_WIDTH+400;
    SDL_RenderCopy(renderer,BGR,NULL,&fullRect);
}

click help(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.h = 400;
    rect.w = 600;
    rect.x = 100;
    rect.y = 200;
    position mouse;
    SDL_Event event;
    SDL_Texture* helps = NULL;
    helps = loadTexture(renderer, "pic/help.bmp");
    SDL_RenderCopy(renderer,helps,NULL,&rect);
    SDL_RenderPresent(renderer);
    while(true)
    {
        if(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
                {
                    return quit_game;
                }
            if(event.type == SDL_MOUSEBUTTONDOWN)
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                mouse.x=event.motion.x;
                mouse.y=event.motion.y;
                }
        }
        if(mouse.x >=350 && mouse.x <=501 && mouse.y >= 550 && mouse.y <= 580) return quit_game;
    }

}

click start(SDL_Renderer* renderer)
{
    position mouse;
    SDL_Event event;
    SDL_Texture* start = NULL;
    start = loadTexture(renderer,"pic/start.bmp");
    SDL_RenderCopy(renderer,start,NULL,NULL);
    SDL_RenderPresent(renderer);
    while(true)
    {
        if(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
                {
                    return quit_game;
                }
            if(event.type == SDL_MOUSEBUTTONDOWN)
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                mouse.x=event.motion.x;
                mouse.y=event.motion.y;
                }
        }
        if(mouse.x >=200 && mouse.x <=590)
        {
            if(mouse.y >= 420 && mouse.y <= 555) return play_game;
            else if (mouse.y >= 600 && mouse.y <= 735)
            {
                if( help(renderer) == quit_game) return play_game;
            }
        }
    }

}

click gameover(SDL_Renderer* renderer, int numScore[5],int score)
{
    ifstream file;
    file.open("bestscore.txt");
    int bestScore;
    file >> bestScore;
    file.close();
    if(score > bestScore)
    {
        bestScore = score;
        ofstream file;
        file.open("bestscore.txt",ios::trunc);
        file << score;
    }

    int num;
    int numBest[5];
    int best = bestScore;
    for(int i = 4;i>=0;i--)
    {
        num = best%10;
        numBest[i] = num;
        best/=10;
    }
    SDL_Event event;
    SDL_Rect backRect;
    SDL_Rect scoreRect;
    SDL_Rect bestScoreRect;
    position mouse;
    backRect.h = 500;
    backRect.w = 400;
    backRect.x = 200;
    backRect.y = 150;
    scoreRect.h = 60;
    scoreRect.w = 30;
    scoreRect.x = 325;
    scoreRect.y = 360;
    bestScoreRect.h = 60;
    bestScoreRect.w = 30;
    bestScoreRect.x = 325;
    bestScoreRect.y = 460;
    SDL_Texture* gameover = NULL;
    gameover = loadTexture(renderer,"pic/overback.bmp");
    SDL_RenderCopy(renderer,gameover,NULL,&backRect);
    for(int i=0;i<5;i++)
    {
        SDL_RenderCopy(renderer,number[numScore[i]],NULL,&scoreRect);
        scoreRect.x+=30;
    }
    for(int i=0;i<5;i++)
    {
        SDL_RenderCopy(renderer,number[numBest[i]],NULL,&bestScoreRect);
        bestScoreRect.x+=30;
    }
    SDL_RenderPresent(renderer);
    while(true)
    {
        if(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
                {
                    return quit_game;
                }
            if(event.type == SDL_MOUSEBUTTONDOWN)
                if(event.button.button == SDL_BUTTON_LEFT)
                    {
                        mouse.x = event.motion.x;
                        mouse.y = event.motion.y;
                    }
        }
        if(mouse.y >= 570 && mouse.y <= 600)
        {
            if(mouse.x >= 230 && mouse.x <= 335) return play_game;
            else if (mouse.x >= 470 && mouse.x <= 530)
            {
                return quit_game;
            }
        }
    }

}








