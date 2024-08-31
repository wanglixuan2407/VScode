#include <stdio.h>
#include "chess.h"

void review()
{
    int rev_num;
    char buf;
    int i;
    int j;

    printf("Do you want to review this game?\n");
    printf("You can enter 1-%d to review the situation.\n",step);
    printf("To end the revision, please enter 0.\n");
    
    for (int k = 0; ; k++)
    {
        scanf("%d",&rev_num);
        scanf("%c",&buf);

        if (rev_num >= 0 && rev_num<= step)
        {
            if (rev_num == 0)
            {
                goto label;
            }
            else
            {
                for (i = COL - 1; i >= 0; i--) 
                {
                    for (j = 0; j <= COL - 1; j++) 
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
                            board[rnd][step][i][j] = '0'; 
                        }
                        else
                        {
                            c_r_crsp(i,j);
                        }
                    }
                }

                for (i = COL - 1; i >= 0; i--) 
                {
                    printf("\n--|---|---|---|---|---|---|---|---|\n");
                    for (j = 0; j <= ROW - 1; j++) 
                    {
                        if (i != 0)
                        {
                            printf("%c | ",board[rnd][rev_num][i][j]);
                        }
                        else
                        {
                            printf(" %c  ",board[rnd][rev_num][i][j]);
                        }
                    }
                }
                printf("\n");
            }
            
        }
        else
        {
            printf("Please enter interger from 0 to %d!\n",step);
        }
    }

    label:
    printf("Revision end.\n");
}