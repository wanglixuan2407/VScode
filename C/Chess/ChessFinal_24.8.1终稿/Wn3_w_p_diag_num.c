#include <stdio.h>
#include "chess.h"

int w_p_diag_num(int i,int j)
{
    int tmp_en_pst = false;
    int legMovNum = 0;
    int nglb_tmpCho = recBoard[rnd][step][i][j];
    int nglb_tmpRch;
    int nglb_tmp_enp;//记录被吃的过路兵enum值

    /*兵所处的a-h改变时，需要变值，此处开一个数组*/
    int W_P[9] = {0,W_P_A,W_P_B,W_P_C,W_P_D,W_P_E,W_P_F,W_P_G,W_P_H};

    /*左斜*/
    if (j - 1 >= 1)
    {
        /*普通斜吃*/
        /*先记录到达位置，之后一直不变*/
        /*白兵推进，i+*/
        nglb_tmpRch = recBoard[rnd][step][i + 1][j - 1];
        
        /*对方子力，可吃*/
        if (nglb_tmpRch <= B_PCE_NUM_HI && nglb_tmpRch >= B_PCE_NUM_LO)
        {
            /*移动*/
            recBoard[rnd][step][i + 1][j - 1] = W_P[j - 1];
            recBoard[rnd][step][i][j] = BLK;

            /*升变*/
            if(i == 7)
            {
                recBoard[rnd][step][i + 1][j - 1] = W_N;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j - 1] = ((j - 1)%2 == 1)?W_B_W:W_B_B;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j - 1] = W_R_PRM;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j - 1] = W_Q;
                legMovNum += w_oprt();
            }
            /*不升变*/
            else
            {
                legMovNum += w_oprt();
            }
            
            /*复原*/
            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i + 1][j - 1] = nglb_tmpRch;
            update_board();
        }
        
        /*吃路过兵*/
        else if (nglb_tmpRch == BLK)
        {
            if (blkEnPasntWrn == NO_B_EN_PASNT_WRN)
            {
                ;
            }
            else
            {
                if (blkEnPasntWrn == j - 1)
                {
                    /*记录暂时被吃的黑兵*/
                    nglb_tmp_enp = recBoard[rnd][step][i][j - 1];
                    /*移动*/
                    recBoard[rnd][step][i][j - 1] = BLK;
                    recBoard[rnd][step][i][j] = BLK;
                    recBoard[rnd][step][i + 1][j - 1] = W_P[j - 1];

                    /*只在吃过路兵检测时临时使用tmp_en_pst*/
                    tmp_en_pst = w_oprt();
                    legMovNum += tmp_en_pst;
                    /*这里承接recBoard，针对一组i，j。因此legMovNum只能为0或1*/
                    if (enPstRec[rnd][step] == false)
                    {
                        if (tmp_en_pst > 0)
                        {
                            enPstRec[rnd][step] = blkEnPasntWrn;
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
                    recBoard[rnd][step][i + 1][j - 1] = nglb_tmpRch;
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
        /*白兵推进，i+*/
        nglb_tmpRch = recBoard[rnd][step][i + 1][j + 1];
        
        /*对方子力，可吃*/
        if (nglb_tmpRch <= B_PCE_NUM_HI && nglb_tmpRch >= B_PCE_NUM_LO)
        {
            /*移动*/
            recBoard[rnd][step][i + 1][j + 1] = W_P[j + 1];
            recBoard[rnd][step][i][j] = BLK;

            /*升变*/
            if(i == 7)
            {
                recBoard[rnd][step][i + 1][j + 1] = W_N;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j + 1] = ((j + 1)%2 == 1)?W_B_W:W_B_B;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j + 1] = W_R_PRM;
                legMovNum += w_oprt();
                recBoard[rnd][step][i + 1][j + 1] = W_Q;
                legMovNum += w_oprt();
            }
            /*不升变*/
            else
            {
                legMovNum += w_oprt();
            }

            /*复原*/
            recBoard[rnd][step][i][j] = nglb_tmpCho;
            recBoard[rnd][step][i + 1][j + 1] = nglb_tmpRch;
            update_board();
        }
        
        /*吃路过兵*/
        else if (nglb_tmpRch == BLK)
        {
            if (blkEnPasntWrn == NO_B_EN_PASNT_WRN)
            {
                ;
            }
            else
            {
                if (blkEnPasntWrn == j + 1)
                {
                    /*记录暂时被吃的黑兵*/
                    nglb_tmp_enp = recBoard[rnd][step][i][j + 1];
                    /*移动*/
                    recBoard[rnd][step][i][j + 1] = BLK;
                    recBoard[rnd][step][i][j] = BLK;
                    recBoard[rnd][step][i + 1][j + 1] = W_P[j + 1];

                    /*只在吃过路兵检测时临时使用tmp_en_pst*/
                    tmp_en_pst = w_oprt();
                    legMovNum += tmp_en_pst;
                    /*这里承接recBoard，针对一组i，j。因此legMovNum只能为0或1*/
                    if (enPstRec[rnd][step] == false)
                    {
                        if (tmp_en_pst > 0)
                        {
                            enPstRec[rnd][step] = blkEnPasntWrn;
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
                    recBoard[rnd][step][i + 1][j + 1] = nglb_tmpRch;
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