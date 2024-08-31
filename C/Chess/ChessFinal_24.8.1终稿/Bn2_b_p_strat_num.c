#include <stdio.h>
#include "chess.h"

int b_p_strat_num(int i,int j)
{
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j]; //接is_wht_win,此时尝试移动兵
    int nglb_tmpRch;

    /*直行*/
    /*直前1格：若非空,则无法直行*/

    /*记下即将到达处:直行1格的子力*/
    nglb_tmpRch = recBoard[rnd][step][i - 1][j];
    if (nglb_tmpRch != BLK)
    {
        ;
    }
    /*直前1格为空*/
    else
    {
        /*移动*/
        recBoard[rnd][step][i - 1][j] = nglb_tmpCho;
        recBoard[rnd][step][i][j] = BLK;
        /*更新棋盘之前考虑升变*/
        if (i == 2)
        {
            /*每种升变都试一次，如果legal，都算在legMovNum内*/
            recBoard[rnd][step][i - 1][j] = B_N;
            legMovNum += b_oprt();
            recBoard[rnd][step][i - 1][j] = (j%2 == 0)?B_B_W:B_B_B;
            legMovNum += b_oprt();
            recBoard[rnd][step][i - 1][j] = B_R_PRM;
            legMovNum += b_oprt();
            recBoard[rnd][step][i - 1][j] = B_Q;
            legMovNum += b_oprt();
        }
        /*i 在3-7,黑兵前进1格,i-1*/
        else
        {
            legMovNum += b_oprt();
        }

        /*复原*/
        recBoard[rnd][step][i][j] = nglb_tmpCho;
        recBoard[rnd][step][i - 1][j] = nglb_tmpRch;
        update_board();
        
        /*最后看前进2格(仍在直前1格为BLK的前提下)*/
        /*记下即将到达处的子力*/
        nglb_tmpRch = recBoard[rnd][step][i - 2][j];

        if (i == 7 && nglb_tmpRch == BLK)//先看i的值，避免i-2越界
        {
            /*移动*/
            recBoard[rnd][step][i - 2][j] = nglb_tmpCho;
            recBoard[rnd][step][i][j] = BLK;

            legMovNum += b_oprt();

            /*复原*/
            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i - 2][j] = nglb_tmpRch;
            update_board();
        }
        else
        {
            ;
        }
    }
    return legMovNum;
}