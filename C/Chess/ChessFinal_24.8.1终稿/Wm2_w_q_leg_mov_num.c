#include <stdio.h>
#include "chess.h"

int w_q_leg_mov_num(int i,int j)
{
    int legMovNum = 0;
    
    legMovNum += w_b_leg_mov_num(i,j);
    legMovNum += w_r_leg_mov_num(i,j);
    
    return legMovNum;
}