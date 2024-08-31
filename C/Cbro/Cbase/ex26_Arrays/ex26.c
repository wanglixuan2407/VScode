#include<stdio.h>
#include <memory.h>

int main()
{
    //array = a data structure that can store many values of the same data type.
    //type variable[]
    //Once compiled, the size of arrays cannot be changed

    double prices[] = {5.0,10.0,15.0,25.0,20.0};
    /*
    double price[5];
    price[0]=5.0;
    ...
    price[4]=20.0;
    */

    char name[] = "Bro";  //A string is an array of indivisual characters

    printf("$%.2lf\n",prices[0]); //index starts with 0

    char array[5];
    memset(array,49,5);//A ASCII = 65 //memset 适用于char数组，而非int
    /*memset(name,int ASCII,size)*/
    /*Before you use memset,you must reference <memory.h>*/
    
    for (int i = 0; i < 5; i++)
    {
        printf("%c\t",array[i]);
    }

    return 0;
}