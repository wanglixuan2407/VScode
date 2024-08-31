#include <stdio.h>
#include "chess.h"

void b_r_thr_map(int i,int j)
{
    int k = 1;
    //i +  向上
    for (int k = 1; k <= 7 ; k++)
    {
        if(i + k > 8)
        {
            break;
        }
        else if(recBoard[rnd][step][i + k][j] != BLK)
        {
            blkThrBoard[rnd][step][i + k][j] ++;
            break;
        }
        else
        {
            blkThrBoard[rnd][step][i + k][j] ++;
        }
        
    }
    
    //i- 向下
    for (int k = 1; k <= 7 ; k++)
    {
        if(i - k < 1)
        {
            break;
        }
        else if(recBoard[rnd][step][i - k][j] != BLK)
        {
            blkThrBoard[rnd][step][i - k][j] ++;
            break;
        }
        else
        {
            blkThrBoard[rnd][step][i - k][j] ++;
        }
    }
    
    //j- 向左
    for (int k = 1; k <= 7 ; k++)
    {
        if(j - k < 1)
        {
            break;
        }
        else if(recBoard[rnd][step][i][j - k] != BLK)
        {
            blkThrBoard[rnd][step][i][j - k] ++;
            break;
        }
        else
        {
            blkThrBoard[rnd][step][i][j - k] ++;
        }
    }

    //j+ 向右
    for (int k = 1; k <= 7 ; k++)
    {
        if(j + k > 8)
        {
            break;
        }
        else if(recBoard[rnd][step][i][j + k] != BLK)
        {
            blkThrBoard[rnd][step][i][j + k] ++;
            break;
        }
        else
        {
            blkThrBoard[rnd][step][i][j + k] ++;
        }
    }
}