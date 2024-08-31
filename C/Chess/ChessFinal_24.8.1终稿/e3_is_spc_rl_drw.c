#include <stdio.h>
#include "chess.h"
#include <memory.h>

/*50回合规则和/3次重复局面和检测,只返回DRAW或CONTI*/
int is_spc_rl_drw()
{
    int rptNum = 0;
    int rptRec[3];

    if (drawStpCnt == 100)
    {
        print_char_board();
        printf("There are 100 steps without pawn move or piece take.\n");
        printf("Draw!\n");
        fprintf(tmp_file,"100-step-Draw\n");
        fprintf(tmp_file,"Result:1/2 - 1/2\n");
        fprintf(file,"100-step-Draw\n");
        fprintf(file,"Result:1/2 - 1/2\n");
        return DRAW;
    }
    else
    {
        ;
    }

    int cnt = 0;

    for (int k = 2; k < step; k += 2)
    {
        if (enPstRec[rnd][step] == enPstRec[rnd][step - k] && cstlRec[rnd][step] == cstlRec[rnd][step - k])
        {
            cnt += 2;
        }
        else
        {
            /*这两个局面不同*/
            goto label;
        }

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                if (recBoard[rnd][step][i][j] != recBoard[rnd][step - k][i][j])
                {
                    /*这两个局面不同*/
                    goto label;
                }
                else
                {
                    cnt ++;
                }
            }
        }

        if (cnt == 66)
        {
            reptRec[rnd][step - k] ++;
            reptRec[rnd][step] = reptRec[rnd][step - k];
        }
        else
        {
            ;
        }
        label:
        cnt = 0;        
    }

    for (int m = 1; m <= step; m++)
    {
        if (reptRec[rnd][m] == 2)
        {
            rptNum ++;
            rptRec[rptNum - 1] = m;
        }
        else
        {
            ;
        }
    }
    if (rptNum == 3)
    {
        print_char_board();
        printf("3-repetition:step %d,step %d,step %d",rptRec[0],rptRec[1],rptRec[2]);
        printf("Draw!\n");
        fprintf(tmp_file,"3-repetition-Draw\n");
        fprintf(tmp_file,"step %d,%d,%d\n",rptRec[0],rptRec[1],rptRec[2]);
        fprintf(tmp_file,"Result:1/2 - 1/2\n");
        fprintf(file,"3-repetition-Draw\n");
        fprintf(file,"step %d,%d,%d\n",rptRec[0],rptRec[1],rptRec[2]);
        fprintf(file,"Result:1/2 - 1/2\n");
        return DRAW;
    }
    else
    {
        ;
    }

    /*两个条件都不满足则不构成和棋*/
    return CONTI;
}