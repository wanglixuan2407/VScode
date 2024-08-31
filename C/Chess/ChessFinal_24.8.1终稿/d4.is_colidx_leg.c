#include <stdio.h>
#include "chess.h"

int is_colidx_leg(char colIdx[MAXIPT])
{
    if (colIdx[0] <= '8' && colIdx[0] >= '1')
    {
        return CRD_LEG;
    }
    else
    {
        return CRD_ILL;
    }   
}