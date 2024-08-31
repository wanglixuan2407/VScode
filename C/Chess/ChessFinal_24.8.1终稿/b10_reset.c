#include <stdio.h>
#include "chess.h"

//reset 不重置rnd
//通过输入赋值的全局变量不用reset

void reset()
{
    step = 0;

    choRchSt = SPR;
    
    choTryNum = 0;
    rchTryNum = 0;

    whosMov = W_TRN;

    wht_K_MovNum = 0;
    blk_K_MovNum = 0;
    wht_R_A_MovNum = 0;
    wht_R_H_MovNum = 0;
    blk_R_A_MovNum = 0;
    blk_R_H_MovNum = 0;

    whtEnPasntWrn = NO_W_EN_PASNT_WRN;
    blkEnPasntWrn = NO_B_EN_PASNT_WRN;

    is_P_Mov = false;
    is_pceTkn = false;
    pceNum = 32;
    drawStpCnt = 0;

    isWht_K_Ckd = W_K_SFE;
    isBlk_K_Ckd = B_K_SFE;
    
    /*数组棋盘复原*/
    int_board_reset(recBoard,iniRecBoard); 
    
    /*recBoard的参数转化为charboard的字符*/
    char_board_set();

    /*注意:先复原recBoard的参数，再恢复charBoard*/
    /*补充：threatmap在自身函数中有更新，此处不必再更新*/
}
