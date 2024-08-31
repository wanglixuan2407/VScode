#include <stdio.h>
#include "chess.h"

/*数组棋盘复原*/

void int_board_reset(int chessBoard[MAXRND][MAXMOV][COL][ROW],int iniChessBoard[COL][ROW])
{
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)  
        {
            chessBoard[rnd][step][i][j]=iniChessBoard[i][j]; 
        }
    }
}