#include <stdio.h>
#include "chess.h"

/*recBoard 8*8盘上数字转化为(char)board的字符
边缘负数:default，break不操作，b5函数会补全边缘*/

void c_r_crsp(int i,int j)
{
    switch (recBoard[rnd][step][i][j])
    {
    case BLK:
    board[rnd][step][i][j] = ' ';
    break;

    case W_K:
    board[rnd][step][i][j] = 'K';
    break;

    case W_Q:
    board[rnd][step][i][j] = 'Q';
    break;

    case W_B_B:
    case W_B_W:
    board[rnd][step][i][j] = 'B';
    break;

    case W_N:
    board[rnd][step][i][j] = 'N';
    break;

    case W_R_A:
    case W_R_H:
    case W_R_PRM:
    board[rnd][step][i][j] = 'R';
    break;

    case B_K:
    board[rnd][step][i][j] = 'k';
    break;

    case B_Q:
    board[rnd][step][i][j] = 'q';
    break;

    case B_B_B:
    case B_B_W:
    board[rnd][step][i][j] = 'b';
    break;

    case B_N:
    board[rnd][step][i][j] = 'n';
    break;

    case B_R_A:
    case B_R_H:
    case B_R_PRM:
    board[rnd][step][i][j] = 'r';
    break;

    case W_P_A:
    case W_P_B:
    case W_P_C:
    case W_P_D:
    case W_P_E:
    case W_P_F:
    case W_P_G:
    case W_P_H:
    board[rnd][step][i][j] = 'P';
    break;

    case B_P_A:
    case B_P_B:
    case B_P_C:
    case B_P_D:
    case B_P_E:
    case B_P_F:
    case B_P_G:
    case B_P_H:
    board[rnd][step][i][j] = 'p';
    break;
    default:break;
    }
}
