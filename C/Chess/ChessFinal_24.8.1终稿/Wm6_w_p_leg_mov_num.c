#include <stdio.h>
#include "chess.h"

int w_p_leg_mov_num(int i,int j)
{
    int legMovNum = 0;

    /*直行:每个兵直行效果都一样*/
    legMovNum += w_p_strat_num(i,j);

    /*斜吃:也可用同一函数表示*/
    legMovNum += w_p_diag_num(i,j);
    
    return legMovNum;
}
