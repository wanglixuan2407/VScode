#include<stdio.h>

int main()
{
    double prices[] = {5.0,10.0,15.0,25.0,20.0};
    int s0 = sizeof(prices);    //sizeof: variable's size: xx bytes
    int s1 = sizeof(prices[0]); //Each element 's size if 8bytes(∵double)
   // printf("Size of array = %d bytes.\n",s);  
   /*ex3: Size of double = 8bytes(64bits)*/
    for(int i = 0; i < s0/s1; i++)
    {
        printf("$%.2lf\n",prices[i]);
    }

    return 0;
}