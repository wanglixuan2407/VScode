#include <stdio.h>
#include "chess.h"

int b_oprt()
{
    int legMovNum = 0;
    int nglb_is_b_k_ckd;

    update_board();
    nglb_is_b_k_ckd = is_blk_k_ckd();

    if (nglb_is_b_k_ckd == B_K_SFE)
    {
        legMovNum ++;
    }

    /*尝试移动后，只要黑王不是SFE，legMovNum都不增加，即此步无法回避将军(包括己方棋子移动到己方王的位置)*/
    else
    {
        ;    
    }
    return legMovNum;
}