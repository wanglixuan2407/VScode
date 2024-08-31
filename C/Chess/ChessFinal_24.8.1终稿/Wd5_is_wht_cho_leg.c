#include <stdio.h>
#include "chess.h"

int is_wht_cho_leg(char colIdx[MAXIPT],char rowLtr[MAXIPT])
{
    /*前提：处于选择状态*/
    if (choRchSt == CHO)
    {
        int i = colidx_cvt(colIdx);
        int j = rowltr_cvt(rowLtr);
        /*不能选中黑棋或空格*/
        if(recBoard[rnd][step][i][j]<= W_PCE_NUM_HI && recBoard[rnd][step][i][j]>= W_PCE_NUM_LO)
        {
            return recBoard[rnd][step][i][j];
        }
        else
        {
            return CHO_ILL;
        }
    }
    else //不可能执行，仅为报错冗余设置
    {
        printf("ERR in file Wd5:You have not chosen a piece!\n");
        return ERR;
    }
}