#include<stdio.h>

int main()
{
    //augmented assignment operators = used to replace a statement where an operator takes a variable as one of its augments and then assigns the result back to the same variable 
    //augmented assignment operators : zeng qiang fu zhi yun suan fu
    // x = x + 1  x += 1
    int x = 10;
    x++;
    x+=2;
    x-=3;
    x*=4;
    x/=5;
    x%=2;
    printf("%d",x);
    return 0;
}