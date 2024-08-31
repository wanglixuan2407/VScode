#include <stdio.h>
#include "chess.h"

/*更新数组棋盘和显示棋盘：
recBoard实时更新，(char)board和threatmap用函数跟随recBoard更新*/

void update_board()
{
    char_board_set(recBoard);
    //print_char_board();

    //printf("TEST:RecordBoard:\n");
    //print_int_board(recBoard);

    //printf("TEST:white_Threat_Map:\n");
    wht_thr_map();
    //print_int_board(whtThrBoard);

    //printf("TEST:black_Threat_Map:\n");
    blk_thr_map();
    //print_int_board(blkThrBoard);
}