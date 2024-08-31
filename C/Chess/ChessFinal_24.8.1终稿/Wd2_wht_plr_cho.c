#include <stdio.h>
#include <string.h>
#include "chess.h"

/*白方选择坐标*/
void wht_plr_cho()
{
    do
    {
        printf("x(a-h):");
        fgets(rowLtr,MAXIPT,stdin);
        strlwr(rowLtr);
    } while (is_rowltr_leg(rowLtr) != CRD_LEG);

    do
    {
        printf("y(1-8):");
        fgets(colIdx,MAXIPT,stdin);
    } while (is_colidx_leg(colIdx) != CRD_LEG);

    choRchSt = CHO;
    choTryNum ++;
}