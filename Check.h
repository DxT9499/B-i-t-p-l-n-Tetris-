#ifndef CHECK_H_INCLUDED
#define CHECK_H_INCLUDED

#include "Perform.h"
#include <SDL_mixer.h>

bool check(position nextPosition[4], int board[BOARD_HEIGHT][BOARD_WIDTH]);
void checkBoard(int board[BOARD_HEIGHT][BOARD_WIDTH],int& score,bool& quit,int numScore[4],Mix_Chunk* chunk,SDL_Renderer* renderer);
#endif // CHECK_H_INCLUDED
