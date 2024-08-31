#include <stdio.h>
#include "chess.h"

int w_p_strat_num(int i,int j)
{
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j];
    int nglb_tmpRch;

    /*直行*/
    /*直前1格：若非空,则无法直行*/
    /*即将到达处:白方直行1格，i + 1*/
    nglb_tmpRch = recBoard[rnd][step][i + 1][j];
    if (nglb_tmpRch != BLK)
    {
        ;
    }
    /*直前1格为空*/
    /*注意：直前1格和直前2格均有可能，逻辑应为在直行1格基础上讨论直行2格，而不是二选一，这与斜吃子/斜吃过路兵不同！*/
    else
    {
        /*移动*/
        recBoard[rnd][step][i + 1][j] = nglb_tmpCho;
        recBoard[rnd][step][i][j] = BLK;
        /*升变*/
        if (i == 7)
        {
            recBoard[rnd][step][i + 1][j] = W_N;
            legMovNum += w_oprt();
            recBoard[rnd][step][i + 1][j] = (j%2 == 0)?W_B_B:W_B_W;
            legMovNum += w_oprt();
            recBoard[rnd][step][i + 1][j] = W_R_PRM;
            legMovNum += w_oprt();
            recBoard[rnd][step][i + 1][j] = W_Q;
            legMovNum += w_oprt();
        }
        /*不升变*/
        else
        {
            legMovNum += w_oprt();
        }
        
        /*复原*/
        recBoard[rnd][step][i][j] = nglb_tmpCho;
        recBoard[rnd][step][i + 1][j] = nglb_tmpRch;
        update_board();

        /*最后看前进2格(仍在直前1格为BLK的前提下)*/
        /*记下即将到达处的子力*/
        nglb_tmpRch = recBoard[rnd][step][i + 2][j];

        if (i == 2 && nglb_tmpRch == BLK)//先看i的值，避免i+2越界
        {
            recBoard[rnd][step][i + 2][j] = nglb_tmpCho;
            recBoard[rnd][step][i][j] = BLK;

            legMovNum += w_oprt();
            /*复原*/

            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i + 2][j] = nglb_tmpRch;
            update_board();
        }
        else
        {
            ;
        }
    }
    return legMovNum;
}