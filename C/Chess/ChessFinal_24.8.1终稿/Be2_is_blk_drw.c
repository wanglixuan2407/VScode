#include <stdio.h>
#include "chess.h"

int is_blk_drw()
{
    int legMovNum = 0;

    if (whosMov == W_TRN)
    {
        /*被将军，跳过和棋判断*/
        if (isWht_K_Ckd != W_K_SFE)
        {
            return CONTI;
        }
        /*未被将军*/
        else if (isWht_K_Ckd == W_K_SFE)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case W_K:
                        legMovNum += w_k_leg_mov_num(i,j);
                        legMovNum += w_cstl_leg_mov_num(i,j);
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

            if (legMovNum >0)
            {
                return CONTI;
            }
            else
            {
                return DRAW;
            } 
        }
        /*冗余：异常情况指示*/
        else
        {
            printf("ERR---file Be2:Some piece occupied white king's location and the error was not detected!\n");
            return DRAW;//强行停止，便于发现问题。
        }
    }
    else
    {
        printf("ERR---file Be2:It should be white to move!\n");
        return DRAW; //强行停止，便于发现问题。
    }
}