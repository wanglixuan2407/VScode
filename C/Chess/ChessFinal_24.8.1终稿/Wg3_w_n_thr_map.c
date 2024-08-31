#include <stdio.h>
#include "chess.h"

void w_n_thr_map(int i,int j)
{
    if (i + 1 <= 8 && j + 2 <= 8)
    {
        whtThrBoard[rnd][step][i + 1][j + 2]++;
    }
    else
    {
        ;
    }

    if(i + 1 <= 8 && j - 2 >= 1)
    {
        whtThrBoard[rnd][step][i + 1][j - 2]++;
    }
    else
    {
        ;
    }

    if(i - 1 >= 1 && j - 2 >= 1)
    {
        whtThrBoard[rnd][step][i - 1][j - 2]++;
    }
    else
    {
        ;
    }

    if(i - 1 >= 1 && j + 2 <= 8)
    {
        whtThrBoard[rnd][step][i - 1][j + 2]++;
    }
    else
    {
        ;
    }

    if(i + 2 <= 8 && j - 1 >= 1)
    {
        whtThrBoard[rnd][step][i + 2][j - 1]++;
    }
    else
    {
        ;
    }

    if(i + 2 <= 8 && j + 1 <= 8)
    {
        whtThrBoard[rnd][step][i + 2][j + 1]++;
    }
    else
    {
        ;
    }

    if(i - 2 >= 1 && j + 1 <= 8)
    {
        whtThrBoard[rnd][step][i - 2][j + 1]++;
    }
    else
    {
        ;
    }

    if(i - 2 >= 1 && j - 1 >= 1)
    {
        whtThrBoard[rnd][step][i - 2][j - 1]++;
    }
    else
    {
        ;
    }
}