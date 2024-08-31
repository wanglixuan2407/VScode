#include<stdio.h>

void printfAge(int *pAge);

int main()
{
    int age = 21; 
    int *pAge = NULL; //good habit:assign NULL when declaring a pointer
                      // pAge, type:int * 
    pAge = &age; // assign address pointing at value
    printfAge(pAge);
    return 0;
}

void printfAge(int *pAge)
{
    printf("You are %d years old.\n",*pAge);
}