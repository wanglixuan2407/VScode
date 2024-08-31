#include <stdio.h>
#include "chess.h"

int w_k_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j]; //接is_blk_win,此时尝试移动王
    int nglb_tmpRch;

    for (int k = -1; k <= 1 ; k++)
    {
        for (int m = -1; m <= 1; m++)
        {
            /*不能原地不动*/
            if (k == 0 && m == 0)
            {
                ;
            }
            else
            {
                /*界内*/
                if(i + k >= 1 && i + k <= 8 && j + m >= 1 && j + m <= 8)
                {
                    /*记下即将到达处的子力*/
                    nglb_tmpRch = recBoard[rnd][step][i + k][j + m];
                    /*不能移动到己方棋子位置*/
                    if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
                    {
                        /*尚未移动，发现将要移动到己方子力位置，不执行任何操作，回到第二个for(注意不是break！！)*/
                        ;
                    }
                    else
                    {
                        /*移动*/
                        recBoard[rnd][step][i + k][j + m] = nglb_tmpCho;
                        recBoard[rnd][step][i][j] = BLK;
                        
                        legMovNum += w_oprt();

                        /*复原*/
                        recBoard[rnd][step][i][j] = nglb_tmpCho;
                        recBoard[rnd][step][i + k][j + m] = nglb_tmpRch;
                        update_board();
                    }
                }
                else
                {
                    ;
                }
            }
        }
    }

    return legMovNum;
}