/*Reverse Polish Notation  nibolanbiaodashi*/

#include <stdio.h>
#include <stdlib.h>
#include "rpn.h"

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while((type = getop(s))!=EOF){
        switch(type){
            case NUMBER:
            push(atof(s));break;
            case '+':
            push(pop()+pop());break;
            case '*':
            push(pop()*pop());break;
            case '-':
            op2 = pop();
            push(pop()-op2);break; //minus has sequence requirement---add a new variable : op2   in main.c
            case '/':
            op2 = pop();
            if(op2!=0.0){
                push(pop()/op2);break;
            }
            else{
                printf("error:zero divisor\n");break;
            }
            case '\n':
            printf("\t%.8g\n",pop());break;   //output the result
            default:
            printf("error:unknown command %s\n",s);break;
        }
    }
    return 0;
}