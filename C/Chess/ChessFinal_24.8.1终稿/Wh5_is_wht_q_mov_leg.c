#include <stdio.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_wht_q_mov_leg()
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
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG; //for 循环结束，仍OK：MOV_LEG
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
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
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
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
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
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
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
    else if (tmpRchCol == tmpChoCol)
    {
        if (tmpRchRow-tmpChoRow >0)
        {
            for (i = 1; i < (tmpRchRow-tmpChoRow); i++)
            {
                if(recBoard[rnd][step][tmpChoCol][tmpChoRow +i] != BLK)
                {
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG;
        }

        else if(tmpRchRow-tmpChoRow <0)
        {
            for (i = 1; i < abs(tmpRchRow-tmpChoRow); i++)
            {
                if(recBoard[rnd][step][tmpChoCol][tmpChoRow -i] != BLK)
                {
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
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
            printf("ERR in file Wh5,please check your code!\n");
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
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
                    return MOV_ILL;
                }
                else
                {
                    ;
                }
            }
            return MOV_LEG;
        }

        else if(tmpRchCol-tmpChoCol <0)
        {
            for (i = 1; i < abs(tmpRchCol-tmpChoCol); i++)
            {
                if(recBoard[rnd][step][tmpChoCol - i][tmpChoRow] != BLK)
                {
                    printf("ILLEGAL:Your queen has jumped over other pieces!\n");
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
            printf("ERR in file Wh5,please check your code!\n");
            return ERR;
        }
    }
    else
    {
        printf("ILLEGAL:Your queen has not move straight or abs(rowchange)==abs(colchange)\n");
        return MOV_ILL;
    }
}