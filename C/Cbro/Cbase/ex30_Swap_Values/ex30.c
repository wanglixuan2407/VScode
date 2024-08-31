#include<stdio.h>
#include<string.h>

int main()
{
    /*
    char x = 'X';
    char y = 'Y';
    char temp;

    temp = x;
    x = y;
    y = temp;*/
    char x[] = "water";
    char y[] = "lemonade";
    char temp[15];

    strcpy(temp,x);//Strlen function is used to assign value to string variables
    strcpy(x,y);   //As for numbers or single char,just use "=" to assign value.
    strcpy(y,temp);

    printf("x=%s\n",x);
    printf("y=%s\n",y);
    
    return 0;
}