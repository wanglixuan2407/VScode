#include <stdio.h>
#include "chess.h"

int is_wht_castling_leg()
{
    /*正被将军时不可易位*/
    if(isWht_K_Ckd == W_K_CKD || isWht_K_Ckd == W_K_CCKKDD)
    {
        printf("When your King is checked,you cannot castling!\n");
        return MOV_ILL;
    } 
    /*易位后被将军：已经在is_blk_mov_leg第一层写到*/
    else
    {
        /*短易位*/
        if (tmpRchRow == 7 && tmpRchCol == 1 && tmpChoRow == 5 && tmpChoCol == 1
        && recBoard[rnd][step][1][8] == W_R_H) //补充:H1白车必须存在，如果未移动就被吃，会导致“无中生有，易位得到一车”
        {
            /*王或H车已经移动过了*/
            if (wht_R_H_MovNum != 0 || wht_K_MovNum != 0)
            {
                printf("When your King or Rook has been moved,you cannot castling!\n");
                return MOV_ILL;
            }
            else
            {
                /*王车中间有子*/
                if(recBoard[rnd][step][1][6] != BLK || tmpRch != BLK)
                {
                    printf("When there are pieces between your king and your rook,you cannot castling!\n");
                    return MOV_ILL;
                }
                else
                {
                    /*白王易位时是否穿过黑方攻击区域*/
                    if(blkThrBoard[rnd][step][1][6] > 0)
                    {
                        printf("If your king get through the unsafe square,the castling is illegal!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        recBoard[rnd][step][1][6] = W_R_H;
                        recBoard[rnd][step][1][8] = BLK;
                        wht_K_MovNum ++;
                        wht_R_H_MovNum ++;
                        return W_ST_CST;
                    }
                }
            }
        }
        /*长易位*/
        else if (tmpRchRow == 3 && tmpRchCol == 1 && tmpChoRow == 5 && tmpChoCol == 1 && recBoard[rnd][step][1][1] == W_R_A)
        {
            /*王或A车已经移动过了*/
            if (wht_R_A_MovNum != 0 || wht_K_MovNum != 0)
            {
                printf("When your King or Rook has been moved,you cannot castling!\n");
                return MOV_ILL;
            }
            else
            {
                /*王车中间有子*/
                if(recBoard[rnd][step][1][2] != BLK || tmpRch != BLK || recBoard[rnd][step][1][4] != BLK)
                {
                    printf("When there are pieces between your king and your rook,you cannot castling!\n");
                    return MOV_ILL;
                }
                else
                {
                    /*白王易位时是否穿过黑方攻击区域*/
                    if(blkThrBoard[rnd][step][1][4] > 0)
                    {
                        printf("If your king get through the unsafe square,the castling is illegal!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        recBoard[rnd][step][1][4] = W_R_A; 
                        recBoard[rnd][step][1][1] = BLK;
                        wht_K_MovNum ++;
                        wht_R_A_MovNum ++;
                        return W_LG_CST;
                    }
                }
            }
        }
        else
        {
            return MOV_ILL;
        } 
    } 
}