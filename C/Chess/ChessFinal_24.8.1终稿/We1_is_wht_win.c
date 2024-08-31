#include <stdio.h>
#include "chess.h"

int is_wht_win()
{
    int legMovNum = 0;

    if (whosMov == B_TRN)
    {
        /*未被将军，跳过获胜判断*/
        if (isBlk_K_Ckd == B_K_SFE)
        {
            return CONTI;
        }
        /*被多个子将军，只能动王*/
        else if (isBlk_K_Ckd == B_K_CCKKDD)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case B_K:
                        legMovNum += b_k_leg_mov_num(i,j);
                        break;

                    default:
                        break;
                    }
                }
            }
            
            if(legMovNum > 0)
            {
                return CONTI;
            }
            else
            {
                return W_WIN;
            } 
        }

        /*只被1子将军，重点讨论*/
        else if (isBlk_K_Ckd == B_K_CKD)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case B_K:
                        legMovNum += b_k_leg_mov_num(i,j);
                        break;
                    case B_Q:
                        legMovNum += b_q_leg_mov_num(i,j);
                        break;
                    case B_B_B:
                    case B_B_W:
                        legMovNum += b_b_leg_mov_num(i,j);
                        break;
                    case B_N:
                        legMovNum += b_n_leg_mov_num(i,j);
                        break;
                    case B_R_A:
                    case B_R_H:
                    case B_R_PRM:
                        legMovNum += b_r_leg_mov_num(i,j);
                        break;
                    case B_P_A:
                    case B_P_B:
                    case B_P_C:
                    case B_P_D:
                    case B_P_E:
                    case B_P_F:
                    case B_P_G:
                    case B_P_H:
                        legMovNum += b_p_leg_mov_num(i,j);
                        break; 
            
                    default:
                        break;
                    }
                }
            }
            if(legMovNum > 0)
            {
                return CONTI;
            }
            else
            {
                return W_WIN;
            }
        }

        /*异常情况指示*/
        else 
        {
            printf("ERR---file We1:Some piece occupied black king's location and the error was not detected!\n");
            return W_WIN;//强行停止，便于发现问题。
        }  
    }
    /*异常情况指示*/
    else
    {
        printf("ERR---file We1:It should be black to move!\n");
        return W_WIN; //强行停止，便于发现问题。
    }
}