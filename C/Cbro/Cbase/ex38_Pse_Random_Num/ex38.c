#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    /* pseudo random numbers = A set of values or elements that are statistically random(DO NOT use this for any sort of cryptographic security)*/

    srand(time(0)); //Use the current time as a seed for random numbers below

    int number1 =(rand() % 7) + 1;  //rand():0-32767  //1-7
    int number2 =(rand() % 7) + 1;
    int number3 =(rand() % 7) + 1;
    printf("%d,%d,%d",number1,number2,number3);


    return 0;
}