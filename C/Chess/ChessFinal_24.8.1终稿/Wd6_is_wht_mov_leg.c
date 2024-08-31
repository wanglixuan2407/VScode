#include <stdio.h>
#include "chess.h"

int is_wht_mov_leg()
{
    int nglb_Is_Wht_K_Ckd;
    /*前提：已经尝试移动*/
    if (choRchSt == RCH)
    {
        nglb_Is_Wht_K_Ckd = is_wht_k_ckd();
        /*将军检测*/
        if(nglb_Is_Wht_K_Ckd == W_K_CKD || nglb_Is_Wht_K_Ckd == W_K_CCKKDD)
        {
            printf("ILLEGAL:After this move,your king is checked!\n");
            return MOV_ILL;
        }
        /*王是否被己方棋子占据*/
        else if (nglb_Is_Wht_K_Ckd == W_K_OCPD)
        {
            printf("ILLEGAL:You have placed your piece on your own king!\n");
            return MOV_ILL;
        }
        
        else
        {
            /*是否落到己方棋子*/
            if (tmpRch <= W_PCE_NUM_HI && tmpRch >= W_PCE_NUM_LO)
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
                case W_K:
                    return is_wht_k_mov_leg();
                    break;

                case W_N:
                    return is_wht_n_mov_leg();
                    break;
                
                case W_B_W:
                case W_B_B:
                    return is_wht_b_mov_leg();
                    break;

                case W_R_A:
                case W_R_H:
                case W_R_PRM:
                    return is_wht_r_mov_leg();
                    break;

                case W_Q:
                    return is_wht_q_mov_leg();
                    break;

                case W_P_A:
                case W_P_B:
                case W_P_C:
                case W_P_D:
                case W_P_E:
                case W_P_F:
                case W_P_G:
                case W_P_H:
                    return is_wht_p_mov_leg();
                    break;
                
                default:
                printf("ERR in file Wd6.Please check your code!\n");
                return ERR;
                    break;
                }     
           }
        }
    }
    else
    {
        printf("ERR in file Wd6:You have not chosen where to reach yet!\n");
        return ERR;
    }
}