#include "Perform.h"
#include <iostream>
#include <SDL_mixer.h>
#include "Create.h"


//kiểm tra vị trí tiếp theo có phù hợp không
bool check(position nextPosition[4], int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    bool avaiable = true;
    for (int i=0;i<4;i++)
    {
        if (nextPosition[i].x < 0) avaiable = false;
        if (nextPosition[i].x >= BOARD_WIDTH) avaiable = false;
    }
    if (avaiable == false) return false;
    for (int i=0;i<4;i++)
    {
        if (nextPosition[i].y < 0) return true;
    }
    for (int i=0;i<4;i++)
    {
        if (nextPosition[i].x<0 || nextPosition[i].x >= BOARD_WIDTH || nextPosition[i].y >= BOARD_HEIGHT)
            return false;
        else if (board[nextPosition[i].y][nextPosition[i].x]!=0) return false;
    }
    return true;
}
//kiểm tra gameover và hàng được lấp đầy
void checkBoard(int board[BOARD_HEIGHT][BOARD_WIDTH],int& score,bool& quit, int numScore[5],Mix_Chunk* chunk,SDL_Renderer* renderer)
{
    for (int i=0;i<BOARD_WIDTH;i++)
        if (board[0][i] != 0)
            if(gameover(renderer,numScore,score) == quit_game)
            {
                Mix_PausedMusic();
                quit = true;
            }
            else if(gameover(renderer,numScore,score) == play_game) playGame(renderer);
    for (int i=0;i<BOARD_HEIGHT;i++)
    {
        bool fullLine = true;
        for (int j=0;j<BOARD_WIDTH;j++)
            if (board[i][j]==0) fullLine = false;
        if (fullLine == true)
        {
            Mix_PauseMusic();
            Mix_PlayChannel(-1,chunk,0);
            score += 100;
            for (int j=i-1;j>=0;j--)
                for (int k=0;k < BOARD_WIDTH;k++)
                {
                    board[j+1][k] = board[j][k];
                    board[j][k] = 0;
                }
            i--;
            Mix_ResumeMusic();
        }
    }

    int num;
    int sc = score;
    for(int i = 4 ; i >= 0 ; i--)
    {
        num= sc%10;
        numScore[i] = num;
        sc=sc/10;
    }
}
