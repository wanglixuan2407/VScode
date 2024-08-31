#include <stdio.h>
#include <string.h>
#include "chess.h"

#define MAX_IPT 100

/*记录对局信息*/
void inf_ipt()
{
    char matchName[MAX_IPT];
    char matchTime[MAX_IPT];
    char plyr1[MAX_IPT];
    char plyr2[MAX_IPT];

    printf("Please enter the matchname.\n");
    printf("If you donot know the matchname,please enter unknown.\n");
    fgets(matchName,MAX_IPT,stdin);
    printf("MatchName: %s",matchName);
    fprintf(tmp_file,"MatchName: %s",matchName);
    fprintf(file,"MatchName: %s",matchName);

    printf("Please enter the matchtime.\n");
    printf("If you donot know the matchtime,please enter unknown.\n");
    fgets(matchTime,MAX_IPT,stdin);
    printf("MatchTime: %s",matchTime);
    fprintf(tmp_file,"MatchTime: %s",matchTime);
    fprintf(file,"MatchTime: %s",matchTime);

    printf("Please enter player1.\n");
    printf("If you donot know player1,please enter unknown.\n");
    fgets(plyr1,MAX_IPT,stdin);
    printf("Player1: %s\n",plyr1);
    fprintf(tmp_file,"Player1: %s",plyr1);
    fprintf(file,"Player1: %s",plyr1);

    printf("Please enter player2.\n");
    printf("If you donot know player2,please enter unknown.\n");
    fgets(plyr2,MAX_IPT,stdin);
    printf("Player2: %s\n",plyr2);
    fprintf(tmp_file,"Player2: %s\n",plyr2);
    fprintf(file,"Player2: %s\n",plyr2);
}