#include <stdio.h>
#include "chess.h"

int b_p_diag_num(int i,int j)
{
    int tmp_en_pst = false;
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j]; //接is_wht_win,此时尝试移动兵
    int nglb_tmpRch;
    int nglb_tmp_enp;//记录被吃的过路兵enum值
    
    /*兵所处的a-h改变时，需要变值，此处开一个数组*/
    int B_P[9] = {0,B_P_A,B_P_B,B_P_C,B_P_D,B_P_E,B_P_F,B_P_G,B_P_H}; 

    /*左斜*/
    if (j - 1 >= 1)
    {
        /*普通斜吃*/
        /*先记录到达位置，之后一直不变*/
        /*黑兵推进，i-*/
        nglb_tmpRch = recBoard[rnd][step][i - 1][j - 1];

        /*对方子力，可吃*/
        if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
        {
            /*移动*/
            recBoard[rnd][step][i - 1][j - 1] = B_P[j - 1];
            recBoard[rnd][step][i][j] = BLK;

            /*升变*/
            if (i == 2)
            {
                recBoard[rnd][step][i - 1][j - 1] = B_N;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j - 1] = ((j - 1)%2 == 1)?B_B_B:B_B_W;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j - 1] = B_R_PRM;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j - 1] = B_Q;
                legMovNum += b_oprt();
            }
            /*不升变*/
            else
            {
                legMovNum += b_oprt();
            }
            
            /*复原*/
            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i - 1][j - 1] = nglb_tmpRch;
            update_board();
        }

        /*吃路过兵*/
        else if (nglb_tmpRch == BLK)
        {
            if (whtEnPasntWrn == NO_W_EN_PASNT_WRN)
            {
                ;
            }
            else
            {
                if (whtEnPasntWrn == j - 1)
                {
                    /*记录暂时被吃的白兵*/
                    nglb_tmp_enp = recBoard[rnd][step][i][j - 1];
                    /*移动*/
                    recBoard[rnd][step][i][j - 1] = BLK;
                    recBoard[rnd][step][i][j] = BLK;
                    recBoard[rnd][step][i - 1][j - 1] = B_P[j - 1];

                    /*只在吃过路兵检测时临时使用tmp_en_pst*/
                    tmp_en_pst = b_oprt();
                    legMovNum += tmp_en_pst;
                    /*这里承接recBoard，针对一组i，j。因此legMovNum只能为0或1*/
                    if (enPstRec[rnd][step] == false)
                    {
                        if (tmp_en_pst > 0)
                        {
                            enPstRec[rnd][step] = whtEnPasntWrn;
                        }
                        else
                        {
                            enPstRec[rnd][step] = false;
                        }
                    }
                    else
                    {
                        ;
                    }

                    /*复原*/
                    recBoard[rnd][step][i][j - 1] = nglb_tmp_enp;
                    recBoard[rnd][step][i][j] = nglb_tmpCho;
                    recBoard[rnd][step][i - 1][j - 1] = nglb_tmpRch;
                    update_board();
                }
                else
                {
                    ;
                }
            }   
        }
        /*落到己方棋子，无效*/
        else
        {
            ;
        }
    }
    /*横向出界，无操作*/
    else
    {
        ;
    }    
        
    /*右斜*/
    if (j + 1 <= 8)
    {
        /*普通斜吃*/
        /*先记录到达位置，之后一直不变*/
        /*黑兵推进，i-*/
        nglb_tmpRch = recBoard[rnd][step][i - 1][j + 1];

        /*对方子力，可吃*/
        if (nglb_tmpRch >= W_PCE_NUM_LO && nglb_tmpRch <= W_PCE_NUM_HI)
        {
            /*移动*/
            recBoard[rnd][step][i - 1][j + 1] = B_P[j + 1];
            recBoard[rnd][step][i][j] = BLK;

            /*升变*/
            if (i == 2)
            {
                recBoard[rnd][step][i - 1][j + 1] = B_N;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j + 1] = ((j + 1)%2 == 1)?B_B_B:B_B_W;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j + 1] = B_R_PRM;
                legMovNum += b_oprt();
                recBoard[rnd][step][i - 1][j + 1] = B_Q;
                legMovNum += b_oprt();
            }
            /*不升变*/
            else
            {
                legMovNum += b_oprt();
            }
            
            /*复原*/
            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i - 1][j + 1] = nglb_tmpRch;
            update_board();
        }

        /*吃路过兵*/
        else if (nglb_tmpRch == BLK)
        {
            if (whtEnPasntWrn == NO_W_EN_PASNT_WRN)
            {
                ;
            }
            else
            {
                if (whtEnPasntWrn == j + 1)
                {
                    /*记录暂时被吃的白兵*/
                    nglb_tmp_enp = recBoard[rnd][step][i][j + 1];
                    /*移动*/
                    recBoard[rnd][step][i][j + 1] = BLK;
                    recBoard[rnd][step][i][j] = BLK;
                    recBoard[rnd][step][i - 1][j + 1] = B_P[j + 1];
                    
                    /*只在吃过路兵检测时临时使用tmp_en_pst*/
                    tmp_en_pst = b_oprt();
                    legMovNum += tmp_en_pst;
                    /*这里承接recBoard，针对一组i，j。因此legMovNum只能为0或1*/
                    if (enPstRec[rnd][step] == false)
                    {
                        if (tmp_en_pst > 0)
                        {
                            enPstRec[rnd][step] = whtEnPasntWrn;
                        }
                        else
                        {
                            enPstRec[rnd][step] = false;
                        }
                    }
                    else
                    {
                        ;
                    }

                    /*复原*/
                    recBoard[rnd][step][i][j + 1] = nglb_tmp_enp;
                    recBoard[rnd][step][i][j] = nglb_tmpCho;
                    recBoard[rnd][step][i - 1][j + 1] = nglb_tmpRch;
                    update_board();
                }
                else
                {
                    ;
                }
            }   
        }
        /*落到己方棋子，无效*/
        else
        {
            ;
        }
    }
    /*横向出界，无操作*/
    else
    {
        ;
    }
    return legMovNum;
}