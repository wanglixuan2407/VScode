#include <stdio.h>
#include "chess.h"

void w_b_thr_map(int i,int j)
{
    int k = 1;

    for (k = 1; k <= 7; k++) 
    /*如果没有其他子力保护，Bishop自身可以被对方的王吃掉，因此k从1开始，最远射程为8-1=7,所以到7结束,出界和被挡问题：加判断条件*/
    {
        // i+ j+方向 出界判断 不可能突破下界，只需看上界
        if (i + k > 8 || j + k > 8)
        {
            break;
        }
        else if(recBoard[rnd][step][i + k][j + k] != BLK)
        {
            whtThrBoard[rnd][step][i + k][j + k] ++;
            break;
        }
        else
        {
            whtThrBoard[rnd][step][i + k][j + k] ++;
        }
        
    }    

    for (k = 1; k <= 7; k++) 
    {
        // i+ j-方向 
        if (i + k > 8 || j - k < 1)
        {
            break;
        }
        else if(recBoard[rnd][step][i + k][j - k] != BLK)
        {
            whtThrBoard[rnd][step][i + k][j - k] ++;
            break;
        }
        else
        {
            whtThrBoard[rnd][step][i + k][j - k] ++;
        }
        
    }

    for (k = 1; k <= 7; k++) 
    {
        // i- j+方向 
        if (i - k < 1 || j + k > 8)
        {
            break;
        }
        else if(recBoard[rnd][step][i - k][j + k] != BLK)
        {
            whtThrBoard[rnd][step][i - k][j + k] ++;
            break;
        }
        else
        {
            whtThrBoard[rnd][step][i - k][j + k] ++;
        }
        
    }

    for (k = 1; k <= 7; k++) 
    {
        // i- j-方向
        if (i - k < 1 || j - k < 1)
        {
            break;
        }
        else if(recBoard[rnd][step][i - k][j - k] != BLK)
        {
            whtThrBoard[rnd][step][i - k][j - k] ++;
            break;
        }
        else
        {
            whtThrBoard[rnd][step][i - k][j - k] ++;
        }
        
    }
}