#include<stdio.h>

int main()
{
    //Attention:When using if statement,
    //ensure that for each conditon, only one statement can be executed!
    int age;
    printf("\nEnter your age\n");
    scanf("%d",&age);
    if(age >= 18){
        printf("You are now signed up\n!");
    }
    else if(age < 0 ){
        printf("You have been born yet!\n");
    }
    else{
        printf("You are too young to sign up!\n");
    }
    return 0;
}