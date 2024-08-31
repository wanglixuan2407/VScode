#include <stdio.h>
#include "chess.h"

int is_rowltr_leg(char rowLtr[MAXIPT])
{
    if (rowLtr[0] <='h' && rowLtr[0] >= 'a')
    {
        return CRD_LEG;
    }
    else
    {
        return CRD_ILL;
    }   
}
