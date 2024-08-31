#include <stdio.h>
#include "chess.h"

void b_q_thr_map(int i,int j)
{
    b_b_thr_map(i,j);
    b_r_thr_map(i,j);
}