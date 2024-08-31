#include <stdio.h>
#include "chess.h"

int b_r_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j]; //接is_wht_win,此时尝试移动车
    int nglb_tmpRch;

    /*右*/
    for (int k = 1; k <= 7; k++)
    {
        /*界内*/
        if(j + k <= 8)
        {
            /*记下即将到达处的子力*/
            nglb_tmpRch = recBoard[rnd][step][i][j + k];
            
            /*不能移动到己方棋子位置*/
            /*由近及远，一旦遇到非空，己方子力不可吃，不可越过；对方子力可吃，不可越过*/
            if (nglb_tmpRch == BLK)
            {
                /*移动*/
                recBoard[rnd][step][i][j + k] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j + k] = nglb_tmpRch;
                update_board();
            }
            /*非空*/
            else
            {
                /*被己方棋子挡住，直接跳出循环*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    break;
                }
                /*被对方棋子挡住，止步于吃子处*/
                else if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
                {
                    /*移动*/
                recBoard[rnd][step][i][j + k] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;

                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j + k] = nglb_tmpRch;
                update_board();

                /*被挡跳出循环*/
                break;
                }
            } 
        }
        /*界外无效*/
        else
        {
            /*近的出界，远的必然出界*/
            break;
        }
    }

    /*左*/
    for (int k = 1; k <= 7; k++)
    {
        /*界内*/
        if(j - k >= 1)
        {
            /*记下即将到达处的子力*/
            nglb_tmpRch = recBoard[rnd][step][i][j - k];
            
            /*不能移动到己方棋子位置*/
            /*由近及远，一旦遇到非空，己方子力不可吃，不可越过；对方子力可吃，不可越过*/
            if (nglb_tmpRch == BLK)
            {
                /*移动*/
                recBoard[rnd][step][i][j - k] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j - k] = nglb_tmpRch;
                update_board();
            }
            /*非空*/
            else
            {
                /*被己方棋子挡住，直接跳出循环*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    break;
                }
                /*被对方棋子挡住，止步于吃子处*/
                else if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
                {
                    /*移动*/
                recBoard[rnd][step][i][j - k] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j - k] = nglb_tmpRch;
                update_board();
                
                /*被挡跳出循环*/
                break;
                }
            } 
        }
        /*界外无效*/
        else
        {
            /*近的出界，远的必然出界*/
            break;
        }
    }

    /*上*/
    for (int k = 1; k <= 7; k++)
    {
        /*界内*/
        if(i + k <= 8)
        {
            /*记下即将到达处的子力*/
            nglb_tmpRch = recBoard[rnd][step][i + k][j];
            
            /*不能移动到己方棋子位置*/
            /*由近及远，一旦遇到非空，己方子力不可吃，不可越过；对方子力可吃，不可越过*/
            if (nglb_tmpRch == BLK)
            {
                /*移动*/
                recBoard[rnd][step][i + k][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i + k][j] = nglb_tmpRch;
                update_board();
            }
            /*非空*/
            else
            {
                /*被己方棋子挡住，直接跳出循环*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    break;
                }
                /*被对方棋子挡住，止步于吃子处*/
                else if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
                {
                    /*移动*/
                recBoard[rnd][step][i + k][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i + k][j] = nglb_tmpRch;
                update_board();
                
                /*被挡跳出循环*/
                break;
                }
            } 
        }
        /*界外无效*/
        else
        {
            /*近的出界，远的必然出界*/
            break;
        }
    }

    /*下*/
    for (int k = 1; k <= 7; k++)
    {
        /*界内*/
        if(i - k >= 1)
        {
            /*记下即将到达处的子力*/
            nglb_tmpRch = recBoard[rnd][step][i - k][j];
            
            /*不能移动到己方棋子位置*/
            /*由近及远，一旦遇到非空，己方子力不可吃，不可越过；对方子力可吃，不可越过*/
            if (nglb_tmpRch == BLK)
            {
                /*移动*/
                recBoard[rnd][step][i - k][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i - k][j] = nglb_tmpRch;
                update_board();
            }
            /*非空*/
            else
            {
                /*被己方棋子挡住，直接跳出循环*/
                if (nglb_tmpRch >= B_PCE_NUM_LO && nglb_tmpRch <= B_PCE_NUM_HI)
                {
                    break;
                }
                /*被对方棋子挡住，止步于吃子处*/
                else if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
                {
                    /*移动*/
                recBoard[rnd][step][i - k][j] = nglb_tmpCho;
                recBoard[rnd][step][i][j] = BLK;
                
                legMovNum += b_oprt();

                /*复原*/
                recBoard[rnd][step][i][j] = nglb_tmpCho;
                recBoard[rnd][step][i - k][j] = nglb_tmpRch;
                update_board();
                
                /*被挡跳出循环*/
                break;
                }
            } 
        }
        /*界外无效*/
        else
        {
            /*近的出界，远的必然出界*/
            break;
        }
    }

    return legMovNum;
}