#include <stdio.h>
#include <time.h>
#include "chess.h"

void end_interface()
{
    printf("Thanks for playing!\n");

    /*记录结束时间*/
    time_t timep;
    time(&timep);
    printf("End time: UTC %s\n",asctime(gmtime(&timep)));

    fprintf(tmp_file,"End time: UTC %s",asctime(gmtime(&timep)));
    fprintf(tmp_file,"/*-----------------------------------*/\n");

    fprintf(file,"End time: UTC %s",asctime(gmtime(&timep)));
    fprintf(file,"/*-----------------------------------*/\n");
}