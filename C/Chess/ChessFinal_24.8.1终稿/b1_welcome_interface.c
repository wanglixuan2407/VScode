#include <stdio.h>
#include <time.h>
#include "chess.h"

void welcome_interface()
{
    /*记录开始时间*/
    time_t timep;
    time(&timep);
    printf("Start time: UTC %s\n",asctime(gmtime(&timep)));

    fprintf(tmp_file,"/*-----------------------------------*/\n");
    fprintf(tmp_file,"Start time: UTC %s\n",asctime(gmtime(&timep)));

    fprintf(file,"/*-----------------------------------*/\n");
    fprintf(file,"Start time: UTC %s\n",asctime(gmtime(&timep)));
    
    printf("*************Welcome to play chess.*************\n");
    printf("Please press enter to start.\n");
    printf("(If you enter other characters,please restart)\n");
}