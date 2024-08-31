#include<stdio.h>

int FindMax(int x,int y); 
                        //function prototype(yuanxing)
                        // a declaraion before main()
                        //Ensures that calls(diaoyong) to a function are made with the correct arguments
int main()
{
    // ternary operator = shortcut to if/else when assigning/returning a value
    //(condition)?value if true:value if false

    int max;
    int a,b;
    printf("Enter an integer a:");
    scanf("%d",&a);
    printf("Enter an integer b:");
    scanf("%d",&b);
    max = FindMax(a,b);
    printf("%d\n",max);
    return 0;
}

int FindMax(int x,int y)
{
    return (x > y) ? x : y;
}