#include<stdio.h>
#include"rpn.h"
#define MAXVAL 100 /*stack's max depth*/
int sp = 0; /*the index of the mext blank space*/
double val[MAXVAL];/*stack*/

void push(double f)
{
    if(sp<MAXVAL){
        val[sp++]=f;
    }
    else{
        printf("error:stack full,cannot push %g\n",f);
    }
}

double pop(void)
{
    if(sp>0){
        return val[--sp];
    }
    else{
        printf("error:stack empty\n");
        return 0.0;
    }
}