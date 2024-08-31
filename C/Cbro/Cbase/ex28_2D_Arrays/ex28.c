#include<stdio.h>
#define ROW 2
#define COL 3

int main()
{
    //2D Array = an array, where each element is an entire array
    //                     useful if you need a matrix,grid,or table of data
     
    int numbers[ROW][COL]={   //2*3 index:0-1;0-2   //This cannot be omitted!
                        {1,2,3},
                        {4,5,6}
                      };
    numbers[0][0] = 7;
    //numbers[5] = 9;  Error
    /*
    //index
    numbers[0][0]=1; 
    numbers[0][1]=2;
    numbers[0][2]=3;
    numbers[1][0]=4;
    numbers[1][1]=5;
    numbers[1][2]=6;
    */
    
    /*We use nested loop to print a 2D Array*/
    int rows = sizeof(numbers)/sizeof(numbers[0]);
    //numbers[0]:the first row of Array:numbers
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    for(int i = 0; i < rows/*ROW*/; i++)
    {
        for (int j = 0; j < columns/*COL*/; j++)
        {
            printf("%d\t",numbers[i][j]);
        }
        printf("\n");
    }

   return 0;
}