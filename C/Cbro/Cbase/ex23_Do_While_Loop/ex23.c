#include<stdio.h>

int main()
{
    //while loop = check the condition, then executes if condition is true.
    //do while loop = always executes, then check the condition.
    
    int number = 0;
    int sum = 0;

    /*
    do{
        printf("Enter a number above 0:");
        scanf("%d",&number);
        if (number > 0)
        {
            sum += number;
        }
    }while (number > 0);     //Enter -1：Calculated
    */


    printf("Enter a number above 0:");
    scanf("%d",&number);
    while (number > 0)
    {
        if (number > 0)
        {
            sum += number;
        }
        printf("Enter a number above 0:");
        scanf("%d",&number);
    }
    
    printf("sum:%d",sum);   //Enter -1:NOT calculated

    return 0;
}