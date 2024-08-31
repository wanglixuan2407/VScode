#include<stdio.h>
#include<string.h>

struct Player
    {
        char name[12];
        int score;
    };
int main()
{
    //struct = collection of related members("variables")
    //         they can be of different data types
    //         listed under one name in a black of memory

    struct Player player1;
    struct Player player2;

    strcpy(player1.name,"Bro"); //string array :use strcpy to assign value
    player1.score = 4;
    strcpy(player2.name,"Bra");
    player2.score = 5;

    printf("%s\n",player1.name);
    printf("%s\n",player2.name);
    printf("%d\n",player1.score);
    printf("%d\n",player2.score);

    return 0;
}
