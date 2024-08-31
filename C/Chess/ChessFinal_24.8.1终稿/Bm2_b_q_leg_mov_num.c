#include <stdio.h>
#include "chess.h"

int b_q_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    
    legMovNum += b_b_leg_mov_num(i,j);
    legMovNum += b_r_leg_mov_num(i,j);

    return legMovNum;
}

