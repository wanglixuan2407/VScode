#include<stdio.h>
#include<string.h>
#define MAX 25

int main()
{
    //while loop = repeats section of code possibly unlimited times.
    //WHILE some condition remains true 
    //a while loop might not execute at all

    char name[MAX];

    while (strlen(name) == 0)
    {
        printf("You did not enter your name.\n");
        printf("What's your name:");
        fgets(name,MAX,stdin);
        name[strlen(name)-1]='\0';
    }
    
    printf("Hello,%s\n",name);

    return 0;
}