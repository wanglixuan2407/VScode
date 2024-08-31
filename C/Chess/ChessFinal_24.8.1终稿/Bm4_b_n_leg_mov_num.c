#include <stdio.h>
#include "chess.h"

int b_n_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j]; //接is_wht_win,此时尝试移动马
    int nglb_tmpRch;
    
    /*上下2左右1*/
    for (int k = -2; k <= 2; k += 4)
    {
        for (int m = -1; m <= 1; m += 2)
        {
            /*界内*/
            if(i + k >= 1 && i + k <= 8 && j + m >= 1 && j + m <= 8)
            {
                /*记下即将到达处的子力*/
                nglb_tmpRch = recBoard[rnd][step][i + k][j + m];
                /*不能移动到己方棋子位置*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    ;
                }
                else
                {
                    /*移动*/
                    recBoard[rnd][step][i + k][j + m] = nglb_tmpCho;
                    recBoard[rnd][step][i][j] = BLK;
                    
                    legMovNum += b_oprt();

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

    /*上下1左右2*/
    for (int k = -1; k <= 1; k += 2)
    {
        for (int m = -2; m <= 2; m += 4)
        {
            /*界内*/
            if(i + k >= 1 && i + k <= 8 && j + m >= 1 && j + m <= 8)
            {
                /*记下即将到达处的子力*/
                nglb_tmpRch = recBoard[rnd][step][i + k][j + m];
                /*不能移动到己方棋子位置*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    ;
                }
                else
                {
                    /*移动*/
                    recBoard[rnd][step][i + k][j + m] = nglb_tmpCho;
                    recBoard[rnd][step][i][j] = BLK;

                    legMovNum += b_oprt();
                    
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

    return legMovNum;
}