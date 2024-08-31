#include <stdio.h>
#include <string.h>
#include "chess.h"

int resign_quest()
{
    char rsn[MAXIPT];
    /*注意实时更新！(char)board和ThreatMap更新相对recBoard有延迟，需要update_board去除此延迟。*/
    /*update_board()和print_char_board()一起使用*/
    update_board();
    print_char_board();

    printf("Resign qustion: agree to resign --- enter r. refuse to resign --- just press enter.");

    fgets(rsn,MAXIPT,stdin);
    strlwr(rsn);

    if (whosMov == W_TRN)
    {
        if (rsn[0] == 'r')
        {
            printf("White resigned!\n");
            fprintf(tmp_file,"\nResult:0 - 1\n");
            fprintf(file,"\nResult:0 - 1\n");
            return W_RSN;
        }
        else
        {
            return NO_RSN;
        }
    }
    else if (whosMov == B_TRN)
    {
        if (rsn[0] == 'r')
        {
            printf("Black resigned!\n");
            fprintf(tmp_file,"\nResult:1 - 0\n");
            fprintf(file,"\nResult:1 - 0\n");
            return B_RSN;
        }
        else
        {
            return NO_RSN;
        }
    }
    else
    {
        printf("ERR---file r,please check your code!\n");
        return B_RSN;//强行停止，便于查找问题
    }
}