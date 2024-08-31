#include<stdio.h>

enum Day{Sun =1,Mon =2,Tue =3,Wed =4,Thu =5,Fri =6,Sat =7};

int main()
{
    //enum = a user defined type of named integer identifiers
    //       help to make a program more readable
    enum Day today = Sat;
    printf("%d\n",today); //Enums are not strings,but they can be treated as int

    if(today == Sun || today == Sat)
    {
        printf("Weekend\n");
    }
    else
    {
        printf("Work\n");
    }

    return 0;
}