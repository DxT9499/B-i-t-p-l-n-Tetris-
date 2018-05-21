#include "Check.h"
#include <string>
#include <SDL.h>
#include "Perform.h"
#include <stdlib.h>
#include "Process.h"

using namespace std;

process::process()
{
    rotation = false;
}
//Tạo khối gạch tiếp theo
void process::createNext()
{
    nextColor = rand()%7+1;
    nextIdShape = rand()%10;
    for(int i = 0; i<4; i++)
    {
        nextBlock[i].x = shape[nextIdShape][i] %2;
        nextBlock[i].y = shape[nextIdShape][i] /2;
    }
}
//Tạo khối gạch hiện tại từ dữ liệu khối gạch tiếp theo
void process::create()
{
    idShape = nextIdShape;
    color = nextColor;
    int randSlot = rand()%9;
    for (int i=0;i<4;i++)
    {
        nowPosition[i].x = nextBlock[i].x + randSlot;
        nowPosition[i].y = nextBlock[i].y - 4 ;
    }
}
//Xử lý di chuyển và xoay
void process::handleMoveAndRotate(int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    position nextPosition[4];
    position center = nowPosition[1];
    for (int i=0;i<4;i++)
    {
        nextPosition[i] = nowPosition[i];
        if (rotation == true)
        {
        int x = nowPosition[i].y-center.y;
        int y = nowPosition[i].x-center.x;
        nextPosition[i].x = center.x - x;
        nextPosition[i].y = center.y + y;
        }
        nextPosition[i].x += x_val;
        nextPosition[i].y += y_val;
    }
    if (check(nextPosition,board))
        for (int i=0;i<4;i++) nowPosition[i] = nextPosition[i];
    rotation = false;
    x_val = 0;
    y_val = 0;
}
//Đặt giá trị cho các ô trong bảng
void process::setBoard(int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    static int i=0;
    i++;
    position nextPosition[4];
    if (i>speedBlock)
    {
         for (int i=0;i<4;i++)
         {
            nextPosition[i] = nowPosition[i];
            nextPosition[i].y++;
         }
        if (check(nextPosition,board))
            for (int i=0;i<4;i++) nowPosition[i] = nextPosition[i];
        else
        {
            for (int i=0;i<4;i++) board[nowPosition[i].y][nowPosition[i].x]=color;
            create();
            createNext();
        }
        i=0;
        //Tang toc do roi cua block
        if (speedBlock>150&&speedUp==20)
            {
                speedBlock--;
                speedUp=0;
            }
        else
            if (speedBlock>50)
                speedUp++;
    }
}
//Xử lý phím nhập vào
void process::handleKey(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {

            case SDLK_UP: if (idShape !=6) rotation=true; break;
            case SDLK_LEFT: x_val--; break;
            case SDLK_RIGHT: x_val++; break;
            case SDLK_DOWN: y_val++; break;
        }
    }
}

//In khối gạch hiện tại ra màn hình
void process::showNow(SDL_Renderer* renderer)
{
    SDL_Rect blockRect;
    blockRect.h = BLOCK_SIZE;
    blockRect.w = BLOCK_SIZE;
    blockRect.x = 0;
    blockRect.y = 0;
    for (int i=0;i<4;i++)
    {
        blockRect.x = nowPosition[i].x * BLOCK_SIZE;
        blockRect.y = nowPosition[i].y * BLOCK_SIZE;
        SDL_RenderCopy(renderer,colorBlock[color],NULL,&blockRect);
    }

}
//In ra khoi gạch tiếp theo
void process::showNext(SDL_Renderer* renderer)
{
    SDL_Rect nextBlockRect;
    nextBlockRect.h = BLOCK_SIZE;
    nextBlockRect.w = BLOCK_SIZE;
    nextBlockRect.x = 0;
    nextBlockRect.y = 0;
    for(int i=0;i<4;i++)
    {
        nextBlockRect.x = nextBlock[i].x * BLOCK_SIZE + NEXT_BLOCK_X;
        nextBlockRect.y = nextBlock[i].y * BLOCK_SIZE + NEXT_BLOCK_Y;
        SDL_RenderCopy(renderer,colorBlock[nextColor],NULL,&nextBlockRect);
    }

}


