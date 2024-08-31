#include <stdio.h>
#include "chess.h"

/*打印数组棋盘，边缘负数用于确认位置，已经初始化，只需对核心8*8棋盘进行操作*/
/*用于检验，确认程序运行无误后结束使命*/

void print_int_board(int chessBoard[MAXRND][MAXMOV][COL][ROW])
{
    for (int i = COL - 1; i >= 0; i--) 
    {
        for (int j = 0; j <= ROW - 1; j++) 
        {
                printf("%-d\t ",chessBoard[rnd][step][i][j]);
        }
        printf("\n");
    }
    printf("\n");
}