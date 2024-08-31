#include <stdio.h>
#include "chess.h"

void b_k_thr_map(int i,int j)
{
    /*王不可能直接到另一个王的位置*/
    blkThrBoard[rnd][step][i][j]++;
    
    if(i == 1 && j == 1)
    {
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i+1][j+1]++;
    }
    else if(i == 1 && j == 8)
    {
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i][j-1]++;
        blkThrBoard[rnd][step][i+1][j-1]++;
    }
    else if(i == 8 && j == 1)
    {
        blkThrBoard[rnd][step][i-1][j]++;
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i-1][j+1]++;
    }
    else if(i == 8 && j == 8)
    {
        blkThrBoard[rnd][step][i-1][j]++;
        blkThrBoard[rnd][step][i][j-1]++;
        blkThrBoard[rnd][step][i-1][j-1]++;
    }
    else if(i > 1 && i < 8 && j == 1)
    {
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i+1][j+1]++;
        blkThrBoard[rnd][step][i-1][j+1]++;
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i-1][j]++;
    }
    else if(i > 1 && i < 8 && j == 8)
    {
        blkThrBoard[rnd][step][i][j-1]++;
        blkThrBoard[rnd][step][i+1][j-1]++;
        blkThrBoard[rnd][step][i-1][j-1]++;
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i-1][j]++;
    }
    else if(j > 1 && j < 8 && i == 1)
    {
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i+1][j+1]++;
        blkThrBoard[rnd][step][i+1][j-1]++;
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i][j-1]++;
    }
    else if(j > 1 && j < 8 && i == 8)
    {
        blkThrBoard[rnd][step][i-1][j]++;
        blkThrBoard[rnd][step][i-1][j+1]++;
        blkThrBoard[rnd][step][i-1][j-1]++;
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i][j-1]++;
    }
    else
    {
        blkThrBoard[rnd][step][i-1][j]++;
        blkThrBoard[rnd][step][i-1][j+1]++;
        blkThrBoard[rnd][step][i-1][j-1]++;
        blkThrBoard[rnd][step][i][j+1]++;
        blkThrBoard[rnd][step][i][j-1]++;
        blkThrBoard[rnd][step][i+1][j]++;
        blkThrBoard[rnd][step][i+1][j+1]++;
        blkThrBoard[rnd][step][i+1][j-1]++;
    }
}