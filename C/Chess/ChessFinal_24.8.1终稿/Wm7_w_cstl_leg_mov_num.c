#include <stdio.h>
#include "chess.h"

int w_cstl_leg_mov_num(int i,int j)
{
    int legMovNum = 0;

    /*短易位检测*/
    if (wht_K_MovNum == 0 && wht_R_H_MovNum == 0 && recBoard[rnd][step][1][8] == W_R_H)
    {
        if (blkThrBoard[rnd][step][1][6] == 0 && blkThrBoard[rnd][step][1][7] == 0 && recBoard[rnd][step][1][6] == BLK && recBoard[rnd][step][1][7] == BLK)
        {
            legMovNum ++;
            cstlRec[rnd][step] = W_ST_CST_OK;
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }
    
    /*长易位检测*/
    if (wht_K_MovNum == 0 && wht_R_A_MovNum == 0 && recBoard[rnd][step][1][1] == W_R_A)
    {
        if (blkThrBoard[rnd][step][1][4] == 0 && blkThrBoard[rnd][step][1][3] == 0 && recBoard[rnd][step][1][2] == BLK && recBoard[rnd][step][1][3] == 0 && recBoard[rnd][step][1][4] == BLK)
        {
            legMovNum ++;
            cstlRec[rnd][step] = W_LG_CST_OK;
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }

    switch (legMovNum)
    {
    case 2:
        cstlRec[rnd][step] = W_CSTS_OK;
        break;
    case 0:
        cstlRec[rnd][step] = false;
        break;
    default:
        break;
    }

    return legMovNum;
}