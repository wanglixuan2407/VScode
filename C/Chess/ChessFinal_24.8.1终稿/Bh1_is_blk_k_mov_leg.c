#include <stdio.h>
#include <math.h> 
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_blk_k_mov_leg()
{
    if (abs(tmpRchCol-tmpChoCol) <= 1 && abs(tmpRchRow-tmpChoRow) <= 1)
    {
        blk_K_MovNum ++;
        return MOV_LEG;
    }
    else if(is_blk_castling_leg() != MOV_ILL)
    {
        // 王 A车/H车移动数各+1，在is_blk_castling_leg函数写
        return MOV_LEG;
    }
    else
    {
        return MOV_ILL;
    }
}