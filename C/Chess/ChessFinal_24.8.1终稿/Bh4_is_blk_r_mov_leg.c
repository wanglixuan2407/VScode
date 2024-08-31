#include <stdio.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_blk_r_mov_leg()
{
    int i = 1;
    if (tmpRchCol == tmpChoCol)
    {
        if (tmpRchRow-tmpChoRow >0)
        {
            for (i = 1; i < (tmpRchRow-tmpChoRow); i++)
            {
                if(recBoard[rnd][step][tmpChoCol][tmpChoRow +i] != BLK)
                {
                    printf("ILLEGAL:Your rook has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            if(tmpCho == B_R_A)
            {
                blk_R_A_MovNum ++;
            }
            else if(tmpCho == B_R_H)
            {
                blk_R_H_MovNum ++;
            }
            else
            {
                printf("ERR in file Bh4,please check your code!\n");
            }
            return MOV_LEG;
        }

        else if(tmpRchRow-tmpChoRow <0)
        {
            for (i = 1; i < abs(tmpRchRow-tmpChoRow); i++)
            {
                if(recBoard[rnd][step][tmpChoCol][tmpChoRow -i] != BLK)
                {
                    printf("ILLEGAL:Your rook has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            if(tmpCho == B_R_A)
            {
                blk_R_A_MovNum ++;
            }
            else if(tmpCho == B_R_H)
            {
                blk_R_H_MovNum ++;
            }
            else
            {
                printf("ERR in file Bh4,please check your code!\n");
            }
            return MOV_LEG;
        }

        else
        {
            printf("ERR in file Bh4,please check your code!\n");
            return ERR;
        }
        
    }
    else if (tmpRchRow == tmpChoRow)
    {
        if (tmpRchCol-tmpChoCol >0)
        {
            for (i = 1; i < (tmpRchCol-tmpChoCol); i++)
            {
                if(recBoard[rnd][step][tmpChoCol + i][tmpChoRow] != BLK)
                {
                    printf("ILLEGAL:Your rook has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            if(tmpCho == B_R_A)
            {
                blk_R_A_MovNum ++;
            }
            else if(tmpCho == B_R_H)
            {
                blk_R_H_MovNum ++;
            }
            else
            {
                printf("ERR in file Bh4,please check your code!\n");
            }
            return MOV_LEG;
        }

        else if(tmpRchCol-tmpChoCol <0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if(recBoard[rnd][step][tmpChoCol - i][tmpChoRow] != BLK)
                {
                    printf("ILLEGAL:Your rook has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            if(tmpCho == B_R_A)
            {
                blk_R_A_MovNum ++;
            }
            else if(tmpCho == B_R_H)
            {
                blk_R_H_MovNum ++;
            }
            else
            {
                printf("ERR in file Bh4,please check your code!\n");
            }
            return MOV_LEG;
        }

        else
        {
            printf("ERR in file Bh4,please check your code!\n");
            return ERR;
        }
    }
    else
    {
        printf("ILLEGAL:Your rook has not moved straight!\n");
        return MOV_ILL;
    }
}