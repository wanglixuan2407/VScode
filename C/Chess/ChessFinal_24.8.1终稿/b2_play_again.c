#include <stdio.h>
#include <ctype.h>
#include "chess.h"

void play_again()
{
    printf("Game over.\nWhiteplayer,do you want to play again?(Y/N):\n");
    printf("If you enter other characters,please restart.\n");
    scanf("%c",&whtResp);
    whtResp = toupper(whtResp);

    printf("Blackplayer, do you want to play again?(Y/N):\n");
    printf("If you enter other characters,please restart.\n");
    scanf("%c",&buf);
    scanf("%c",&blkResp);
    blkResp = toupper(blkResp);
}