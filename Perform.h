#ifndef PERFORM_H_INCLUDED
#define PERFORM_H_INCLUDED

#include<SDL.h>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 800;
const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BLOCK_SIZE = 40;
const int SPEED_COUNT = 200;
const int NEXT_BLOCK_X = 550;
const int NEXT_BLOCK_Y = 120;
const int SCORE_BOARD_WIDTH = 300;
const int SCORE_BOARD_HEIGHT = 120;

enum
{
    NONE,
    RED,
    BLUEE,
    YELLOW,
    PURPLE,
    GREEN,
    BLUE,
    ORANGE,
    TOTAL
};

enum click { play_game , quit_game };

struct position
{
    int x;
    int y;
};

const int shape[10][4] =
{
    2,4,5,6,    //|-
    2,4,5,7,    //S
    1,3,5,7,    //I
    3,5,4,6,    //Z
    3,5,4,7,    //-|
    3,5,7,6,    //J
    2,3,4,5,    //Vuong
    2,3,5,7,    //L
    2,4,3,6,    //L*
    2,5,3,7,    //J*
};

extern SDL_Texture* colorBlock[TOTAL];
extern SDL_Texture* number[11];
extern SDL_Texture* BGR ;
void showScore(int numScore[5] , SDL_Renderer* render);
bool loadBlockAndNumber(SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer,string path);
void showBoard(SDL_Renderer* renderer,int board[BOARD_HEIGHT][BOARD_WIDTH]);
void showBack(SDL_Renderer* renderer);
click help(SDL_Renderer* renderer);
click start(SDL_Renderer* renderer);
click gameover(SDL_Renderer* renderer, int numScore[5], int score);

#endif // PERFORM_H_INCLUDED

