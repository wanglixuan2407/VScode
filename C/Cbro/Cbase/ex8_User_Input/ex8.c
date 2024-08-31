#include<stdio.h> //printf,scanf
#include<string.h> //strlen
#define Edge 25

int main()
{
                // 1st variable declaration
    int age ;   // integer %d
    char name[Edge]; //string %s  

    printf("Whats your name?\n");
    //scanf("%s", name);  //User input
    /*There is a problem: When a blank appears, contents remained will skip to the next scanf*/
    /*fgets can read blank, Enter normally , while scanf cannot.*/ 
    /*scanf has a buffer for blank,\n,etc.,while fgets read all characters unless the number is larger than Edge(personally set)*/
    fgets(name,Edge,stdin); // variable name; size; stdin = standardinput
    name[strlen(name)-1] = '\0'; // Eliminate the 'Enter' in the end
                                 // strlen: string.h 
    printf("How old are you?\n");
    scanf("%d", &age);   //user input

    printf("Hello, %s, how are you?\n",name);
    printf("You are %d years old.\n",age);

}