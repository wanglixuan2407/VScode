#include <stdio.h>
#include "chess.h"

/*白王活动禁区*/

void blk_thr_map()
{
    /*threatmap:每一步开始前复原,再根据recBoard计算*/
    int_board_reset(blkThrBoard,iniThrBoard);

    for (int i = 1; i < COL; i++)
    {
        for (int j = 1; j < ROW; j++)
        {
            switch (recBoard[rnd][step][i][j])
            {
            case B_K:
                b_k_thr_map(i,j);
                break;
            case B_Q:
                b_q_thr_map(i,j);
                break;
            case B_N:
                b_n_thr_map(i,j);
                break;
            case B_B_B:
            case B_B_W:
                b_b_thr_map(i,j);
                break;
            case B_R_A:
            case B_R_H:
            case B_R_PRM:
                b_r_thr_map(i,j);
                break;
            case B_P_A:
                blkThrBoard[rnd][step][i-1][j+1] ++;
            break;
            
            case B_P_H:
                blkThrBoard[rnd][step][i-1][j-1] ++;
            break;

            case B_P_B:
            case B_P_C:
            case B_P_D:
            case B_P_E:
            case B_P_F:
            case B_P_G:
                blkThrBoard[rnd][step][i-1][j+1] ++;
                blkThrBoard[rnd][step][i-1][j-1] ++;
            break;

            default:
                break;
            }
        }  
    }
}