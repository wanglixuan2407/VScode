#include<stdio.h>
#include<string.h>
#define MAX 25

void birthday(char name[], int age);  //declaration before main()

int main()
{ 
    //ATTENTION: In main,we cannot see variables in other functions!
    //A practical solution is declare and definite the variables in main(), and then pass it into other fnuctions.
    /*However this may make the main() unclear because we always learn about the program quickly though functions in main().*/
    char name[MAX];
    int age;
    printf("Please enter your name:");
    fgets(name,MAX,stdin);
    printf("PLease enter your age:");
    scanf("%d",&age);
    name[strlen(name)-1]='\0';
    birthday(name,age);   // Variable's order and datatype must match! See /**/ at the bottom.
    return 0;
}

void birthday(char name[],int age)  //definition after main()
{
    printf("Happy birthday to you,%s!\n",name);
    printf("You are %d years old!\n",age);
}

//This works,too.
/*
void birthday(char x[],int y)  //definition after main()
{
    printf("Happy birthday to you,%s!\n",x);
    printf("You are %d years old!\n",y);
}
*/