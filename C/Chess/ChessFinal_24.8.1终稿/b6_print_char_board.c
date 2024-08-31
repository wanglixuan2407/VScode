#include <stdio.h>
#include "chess.h"

void print_char_board()
{
    for (int i = COL - 1; i >= 0; i--) 
    {
        printf("\n--|---|---|---|---|---|---|---|---|\n");
        for (int j = 0; j <= ROW - 1; j++) 
        {
            if (i != 0)
            {
                printf("%c | ",board[rnd][step][i][j]);
            }
            else
            {
                printf(" %c  ",board[rnd][step][i][j]);
            }
        }
    }
    printf("\n");
}