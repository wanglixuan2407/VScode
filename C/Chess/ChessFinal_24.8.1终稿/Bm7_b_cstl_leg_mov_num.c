#include <stdio.h>
#include "chess.h"

int b_cstl_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    
    /*短易位检测*/
    if (blk_K_MovNum == 0 && blk_R_H_MovNum == 0 && recBoard[rnd][step][8][8] == B_R_H)
    {
        if (whtThrBoard[rnd][step][8][6] == 0 && whtThrBoard[rnd][step][8][7] == 0 && recBoard[rnd][step][8][6] == 0 && recBoard[rnd][step][8][7] == 0)
        {
            legMovNum ++;
            cstlRec[rnd][step] = B_ST_CST_OK; 
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
    if (blk_K_MovNum == 0 && blk_R_A_MovNum == 0 && recBoard[rnd][step][8][1] == B_R_A)
    {
        if (whtThrBoard[rnd][step][8][4] == 0 && whtThrBoard[rnd][step][8][3] == 0 && recBoard[rnd][step][8][2] == 0 && recBoard[rnd][step][8][3] == 0 && recBoard[rnd][step][8][4] == 0)
        {
            legMovNum ++;
            cstlRec[rnd][step] = B_LG_CST_OK; 
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
        cstlRec[rnd][step] = B_CSTS_OK;
        break;
    case 0:
        cstlRec[rnd][step] = false;
        break;
    default:
        break;
    }
    return legMovNum;
}