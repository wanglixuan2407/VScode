#include <stdio.h>
#include "chess.h"

int is_blk_mov_leg()
{
    int nglb_Is_Blk_K_Ckd;
    /*前提：已经尝试移动*/
    if (choRchSt == RCH)
    {
        nglb_Is_Blk_K_Ckd = is_blk_k_ckd();
        /*将军检测*/
        if(nglb_Is_Blk_K_Ckd == B_K_CKD || nglb_Is_Blk_K_Ckd == B_K_CCKKDD)
        {
            printf("ILLEGAL:After this move,your king is checked!\n");
            return MOV_ILL;
        }
        /*王是否被己方棋子占据*/
        else if(nglb_Is_Blk_K_Ckd == B_K_OCPD)
        {
            printf("ILLEGAL:You have placed your piece on your own king!\n");
            return MOV_ILL;
        }
        
        else
        {
            /*是否落到己方棋子*/
            if (tmpRch <= B_PCE_NUM_HI && tmpRch >= B_PCE_NUM_LO)  
            {
                printf("Illegal: You placed your piece on the same color piece!\n");
                return MOV_ILL;
            }
            /*是否原地不动*/
            else if ((tmpRchCol == tmpChoCol) && (tmpRchRow == tmpChoRow))  
            {
                printf("Illegal: You placed your piece on itself!\n");
                return MOV_ILL;
            }
            /*以上均不违规时，检测棋子走法*/
            else
            {
                switch (tmpCho)
                {
                case B_K:
                    return is_blk_k_mov_leg();
                    break;

                case B_N:
                    return is_blk_n_mov_leg();
                    break;
                
                case B_B_W:
                case B_B_B:
                    return is_blk_b_mov_leg();
                    break;

                case B_R_A:
                case B_R_H:
                case B_R_PRM:
                    return is_blk_r_mov_leg();
                    break;

                case B_Q:
                    return is_blk_q_mov_leg();
                    break;

                case B_P_A:
                case B_P_B:
                case B_P_C:
                case B_P_D:
                case B_P_E:
                case B_P_F:
                case B_P_G:
                case B_P_H:
                    return is_blk_p_mov_leg();
                    break;
                
                default:
                printf("ERR in file Bd6.Please check your code!\n");
                return ERR;
                    break;
                }     
           }
        }
    }
    else
    {
        printf("ERR in file Bd6:You have not chosen where to reach yet!\n");
        return ERR;
    }
}