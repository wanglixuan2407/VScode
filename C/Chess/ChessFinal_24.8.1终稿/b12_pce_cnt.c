#include <stdio.h>
#include "chess.h"

/*记录剩余棋子数*/
int pce_cnt()
{
    int pce_rmn = 0;//初始化，否则会生成随机数

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (recBoard[rnd][step][i][j] != BLK) 
            {
                pce_rmn ++;
            }
            else
            {
                ;
            }
        }
    }
    return pce_rmn;
}