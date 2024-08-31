#include <stdio.h>
#include "chess.h"

int is_blk_k_ckd()
{
    int found = 0;//是否找到王
    int x;
    int y;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if(recBoard[rnd][step][i][j] == B_K)
            {
                found ++;
                x = i;
                y = j;
                break;
            }
            else
            {
                ;
            }
        }
    }
    
    if(found)
    {
        return (whtThrBoard[rnd][step][x][y] > 0)?((whtThrBoard[rnd][step][x][y] > 1)?B_K_CCKKDD:B_K_CKD):B_K_SFE;
    }
    /*没找到王，己方某个棋子被移到己方国王处,违规*/
    else
    {
        return B_K_OCPD;
    }   
}