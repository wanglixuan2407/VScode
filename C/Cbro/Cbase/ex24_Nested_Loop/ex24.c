#include<stdio.h>

int main()
{
    // nestedd loop = a loop inside of another loop

    int rows;
    int columns;
    char buffer; // \n
    char symbol;

    printf("Enter row number:");
    scanf("%d",&rows);
    
    printf("Enter column number:");
    scanf("%d",&columns);  // \n:next scan function picks that up!
 
    scanf("%c",&buffer);  
    /*create a buffer in order that scanf input int and char*/
   
    printf("Enter a symbol to use:");
    scanf("%c",&symbol);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            printf("%c",symbol);
        }
        printf("\n");
    }
    
}