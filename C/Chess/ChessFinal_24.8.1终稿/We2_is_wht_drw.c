#include <stdio.h>
#include "chess.h"

int is_wht_drw()
{
    int legMovNum = 0;

    if (whosMov == B_TRN)
    {
        /*被将军，跳过和棋判断*/
        if(isBlk_K_Ckd != B_K_SFE)
        {
            return CONTI;
        }
        /*未被将军*/
        else if (isBlk_K_Ckd == B_K_SFE)
        {
            for (int i = 1; i < COL; i++)
            {
                for (int j = 1; j < ROW; j++)
                {
                    switch (recBoard[rnd][step][i][j])
                    {
                    case B_K:
                        legMovNum += b_k_leg_mov_num(i,j);
                        legMovNum += b_cstl_leg_mov_num(i,j);
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
            printf("ERR---file We2:Some piece occupied black king's location and the error was not detected!\n");
            return DRAW;//强行停止，便于发现问题。
        } 
    }
    else
    {
        printf("ERR---file We2:It should be black to move!\n");
        return DRAW; //强行停止，便于发现问题。
    }
}