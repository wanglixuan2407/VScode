#include<stdio.h>
#include"rpn.h"
#define BUFSIZE 100
int bufp = 0;
char buf[BUFSIZE];
int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
    if(bufp>=BUFSIZE){
        printf("ungetch:too many characters\n");
    }
    else{
        buf[bufp++]=c;
    }
}