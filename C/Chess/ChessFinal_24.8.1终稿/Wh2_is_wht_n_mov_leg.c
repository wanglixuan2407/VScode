#include <stdio.h>
#include <math.h>
#include "chess.h"

/*DECLARATION*/
/*The functions below is combined with legalJudge*/
/*default condition: king unchecked, the chosen piece is not placed on its initial location*/
int is_wht_n_mov_leg()
{
    if(abs(tmpRchRow-tmpChoRow)== 1 && abs(tmpRchCol-tmpChoCol)== 2)
        {
            return MOV_LEG;
        }
    else if(abs(tmpRchRow-tmpChoRow) == 2 && abs(tmpRchCol-tmpChoCol) == 1)
        {
            return MOV_LEG;
        }
    else
        {
            printf("Your Knight move is illegal!\n");
            return MOV_ILL;
        }
}