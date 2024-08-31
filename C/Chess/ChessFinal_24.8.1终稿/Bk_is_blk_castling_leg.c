#include <stdio.h>
#include "chess.h"

int is_blk_castling_leg()
{
    /*正被将军时不可易位*/
    if(isBlk_K_Ckd == B_K_CKD || isBlk_K_Ckd == B_K_CCKKDD)
    {
        printf("When your King is checked,you cannot castling!\n");
        return MOV_ILL;
    } 
    /*易位后被将军：已经在is_blk_mov_leg第一层写到*/
    else
    {
        /*短易位*/
        if (tmpRchRow == 7 && tmpRchCol == 8 && tmpChoRow == 5 && tmpChoCol == 8 && recBoard[rnd][step][8][8] == B_R_H) 
        {
            /*王或H车已经移动过了*/
            if (blk_R_H_MovNum != 0 || blk_K_MovNum != 0) 
            {
                printf("When your King or Rook has been moved,you cannot castling!\n");
                return MOV_ILL;
            }
            else
            {
                /*王车中间有子*/
                if(recBoard[rnd][step][8][6] != BLK || tmpRch != BLK) 
                {
                    printf("When there are pieces between your king and your rook,you cannot castling!\n");
                    return MOV_ILL;
                }
                else
                {
                    /*黑王易位时是否穿过白方攻击区域*/
                    if(whtThrBoard[rnd][step][8][6] > 0)
                    {
                        printf("If your king get through the unsafe square,the castling is illegal!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        recBoard[rnd][step][8][6] = B_R_H; 
                        recBoard[rnd][step][8][8] = BLK;
                        blk_K_MovNum ++;
                        blk_R_H_MovNum ++;
                        return B_ST_CST;
                    }
                }
            }
        }
        /*长易位*/
        else if (tmpRchRow == 3 && tmpRchCol == 8 && tmpChoRow == 5 && tmpChoCol == 8 && recBoard[rnd][step][8][1] == B_R_A)
        {
            /*王或H车已经移动过了*/
            if (blk_R_A_MovNum != 0 || blk_K_MovNum != 0)
            {
                printf("When your King or Rook has been moved,you cannot castling!\n");
                return MOV_ILL;
            }
            else
            {
                /*王车中间有子*/
                if(recBoard[rnd][step][8][2] != BLK || tmpRch != BLK || recBoard[rnd][step][8][4] != BLK) 
                {
                    printf("When there are pieces between your king and your rook,you cannot castling!\n");
                    return MOV_ILL;
                }
                else
                {
                    /*黑王易位时是否穿过白方攻击区域*/
                    if(whtThrBoard[rnd][step][8][4] > 0)
                    {
                        printf("If your king get through the unsafe square,the castling is illegal!\n");
                        return MOV_ILL;
                    }
                    else
                    {
                        recBoard[rnd][step][8][4] = B_R_A; 
                        recBoard[rnd][step][8][1] = BLK;
                        blk_K_MovNum ++;
                        blk_R_A_MovNum ++;
                        return B_LG_CST;
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