#include <stdio.h>
#include "chess.h"

int is_blk_win()
{
    int legMovNum = 0;

    if (whosMov == W_TRN)
    {
        /*未被将军，跳过获胜判断*/
        if (isWht_K_Ckd == W_K_SFE)
        {
            return CONTI;
        }
        /*被多个子将军，只能动王*/
        else if (isWht_K_Ckd == W_K_CCKKDD)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case W_K:
                        legMovNum += w_k_leg_mov_num(i,j);
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
                return B_WIN;
            } 
        }

        /*只被1子将军，重点讨论*/
        else if (isWht_K_Ckd == W_K_CKD)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case W_K:
                        legMovNum += w_k_leg_mov_num(i,j);
                        break;
                    case W_Q:
                        legMovNum += w_q_leg_mov_num(i,j);
                        break;
                    case W_B_B:
                    case W_B_W:
                        legMovNum += w_b_leg_mov_num(i,j);
                        break;
                    case W_N:
                        legMovNum += w_n_leg_mov_num(i,j);
                        break;
                    case W_R_A:
                    case W_R_H:
                    case W_R_PRM:
                        legMovNum += w_r_leg_mov_num(i,j);
                        break;
                    case W_P_A:
                    case W_P_B:
                    case W_P_C:
                    case W_P_D:
                    case W_P_E:
                    case W_P_F:
                    case W_P_G:
                    case W_P_H:
                        legMovNum += w_p_leg_mov_num(i,j);
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
                return B_WIN;
            }
        }

        /*异常情况指示*/
        else 
        {
            printf("ERR---file We1:Some piece occupied white king's location and the error was not detected!\n");
            return B_WIN;//强行停止，便于发现问题。
        }  
    }
    /*异常情况指示*/
    else
    {
        printf("ERR---file We1:It should be white to move!\n");
        return B_WIN; //强行停止，便于发现问题。
    }
}
