#include <stdio.h>
#include "chess.h"

void fprint_final()
{
    int i;
    int j;

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
        fprintf(tmp_file,"\n--|---|---|---|---|---|---|---|---|\n");
        fprintf(file,"\n--|---|---|---|---|---|---|---|---|\n");
        for (j = 0; j <= ROW - 1; j++) 
        {
            if (i != 0)
            {
                fprintf(tmp_file,"%c | ",board[rnd][step][i][j]);
                fprintf(file,"%c | ",board[rnd][step][i][j]);
            }
            else
            {
                fprintf(tmp_file,"%c   ",board[rnd][step][i][j]);
                fprintf(file,"%c   ",board[rnd][step][i][j]);
            }
        }
    }
    fprintf(tmp_file,"\n/*-----------------------------------*/\n");
    fprintf(file,"\n/*-----------------------------------*/\n");
}