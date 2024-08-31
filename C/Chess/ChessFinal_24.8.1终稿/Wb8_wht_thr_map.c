#include <stdio.h>
#include "chess.h"

/*黑王活动禁区*/

void wht_thr_map()
{
    /*threatmap:每一步开始前复原,再根据recBoard计算*/
    int_board_reset(whtThrBoard,iniThrBoard);
    
    for (int i = 1; i < COL; i++)
    {
        for (int j = 1; j < ROW; j++)
        {
            switch (recBoard[rnd][step][i][j])
            {
            case W_K:
                w_k_thr_map(i,j);
                break;
            case W_Q:
                w_q_thr_map(i,j);
                break;
            case W_N:
                w_n_thr_map(i,j);
                break;
            case W_B_B:
            case W_B_W:
                w_b_thr_map(i,j);
                break;
            case W_R_A:
            case W_R_H:
            case W_R_PRM:
                w_r_thr_map(i,j);
                break;
            case W_P_A:
                whtThrBoard[rnd][step][i+1][j+1] ++;
            break;
            
            case W_P_H:
                whtThrBoard[rnd][step][i+1][j-1] ++;
            break;

            case W_P_B:
            case W_P_C:
            case W_P_D:
            case W_P_E:
            case W_P_F:
            case W_P_G:
                whtThrBoard[rnd][step][i+1][j+1] ++;
                whtThrBoard[rnd][step][i+1][j-1] ++;
            break;

            default:
                break;
            }
        }  
    }
}