#include <stdio.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_blk_b_mov_leg()
{
    int i = 1;//循环索引

    if (abs(tmpRchCol-tmpChoCol) == abs(tmpRchRow-tmpChoRow))
    {
        /*col+ row+*/
        if ((tmpRchCol-tmpChoCol) >0 && (tmpRchRow-tmpChoRow) >0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if (recBoard[rnd][step][tmpChoCol + i][tmpChoRow + i] != BLK)
                {
                    printf("ILLEGAL:Your bishop has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG; 
        }
        else
        {
            ;
        }

        /*col+ row-*/
        if ((tmpRchCol-tmpChoCol) >0 && (tmpRchRow-tmpChoRow) <0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if (recBoard[rnd][step][tmpChoCol + i][tmpChoRow - i] != BLK)
                {
                    printf("ILLEGAL:Your bishop has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG;
        }
        else
        {
            ;
        }

        /*col- row+*/
        if ((tmpRchCol-tmpChoCol) <0 && (tmpRchRow-tmpChoRow) >0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if (recBoard[rnd][step][tmpChoCol - i][tmpChoRow + i] != BLK)
                {
                    printf("ILLEGAL:Your bishop has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG;
        }
        else
        {
            ;
        }

        /*col- row-*/
        if ((tmpRchCol-tmpChoCol) <0 && (tmpRchRow-tmpChoRow) <0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if (recBoard[rnd][step][tmpChoCol - i][tmpChoRow - i] != BLK)
                {
                    printf("ILLEGAL:Your bishop has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG;
        }
        else
        {
            ;
        }
        
    }
    else
    {
        printf("ILLEGAL:abs(rowchange) != abs(colchange)\n");
        return MOV_ILL;
    }
}