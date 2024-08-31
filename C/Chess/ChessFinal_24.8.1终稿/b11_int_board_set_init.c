#include <stdio.h>
#include "chess.h"

/*一方进行合规移动后，进入下一步，此时step+1，要将recBoard[rnd][step][i][j]更新到与上一步结束时相同的局面，否则下一步会因没有初始局面而出错*/

void int_board_set_init(int chessBoard[MAXRND][MAXMOV][COL][ROW])
{
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)  
        {
            chessBoard[rnd][step][i][j]=chessBoard[rnd][step-1][i][j]; 
        }
    }
}