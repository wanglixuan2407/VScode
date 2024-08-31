#include<stdio.h>
#include<string.h>
#define ROW 2
#define COL 3

int main()
{
    char cars[][10] = {"Mustang","Corvette","Camaro"};
    /*ex26 A string is an array of indivisual characters
    10: 1 string cannot have more than 10 characters,
    size of every string in string cars [][10]is 10bytes
    string array: char cars[][10]
    So,sizeof(cars)/sizeof(cars[0]):OK
    */
    //We cannot change any element directly in strings
    //cars[0][0]="AAA"; // Incorrect!
    //cars[0]="AAA"// Incorrect!
    //However,array of numbers canbe modified like this.
    strcpy(cars[0],"Tesla");  //strcpy :change element in string array
    //printf("%d",sizeof(cars[0]));
    for (int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)
    {
        printf("%s\n",cars[i]);
    }
    
    char word[ROW][COL][10] = {
                                    {"DSFK","DFSK","FIWE"},
                                    {"FHRD","ASFF","EYOM"}
                                };
    for (int j = 0;j < ROW; j++)  //Detail : Index or Size ,< or <= 
    {
        for(int k = 0 ;k < COL; k++)
        {
            printf("%s\t",word[j][k]);
        }
        printf("\n");
    } 

    return 0;
}