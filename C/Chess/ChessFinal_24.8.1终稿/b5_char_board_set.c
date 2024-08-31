#include <stdio.h>
#include "chess.h"

/*recBoard的参数转化为charboard的字符*/
/*边缘a-h,1-8转成字符*/

void char_board_set()
{
    for (int i = COL - 1; i >= 0; i--) 
    {
        for (int j = 0; j <= COL - 1; j++) 
        {
            if (i == 0 && j != 0)
            {
                board[rnd][step][i][j] = (char)(j +'a'- 1);
            }
            else if(j == 0 && i != 0)
            {
                board[rnd][step][i][j] = (char)(i +'0');
            }
            else if(i == 0 && j == 0)
            {
                board[rnd][step][i][j] = '\0'; //(0,0)处没有字符(不是空白符)
            }
            else
            {
                c_r_crsp(i,j);
            }
        }
    }
}