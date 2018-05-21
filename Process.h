#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include <SDL.h>
#include "Perform.h"

class process
{

public:
    process();
    void create();
    void createNext();
    void handleMoveAndRotate(int board[BOARD_HEIGHT][BOARD_WIDTH]);
    void setBoard(int board[BOARD_HEIGHT][BOARD_WIDTH]);
    void handleKey(SDL_Event e);
    void showNow(SDL_Renderer* renderer);
    void showNext(SDL_Renderer* renderer);
private:
    int speedBlock=SPEED_COUNT;
    int speedUp=0;
    int color;
    int nextColor;
    int idShape;
    int nextIdShape;
    int x_val = 0;
    int y_val = 0;
    position nowPosition[4];
    position nextBlock[4];
    bool rotation;
};

#endif // PROCESS_H_INCLUDED
