#include<stdio.h>

void sort(int array[],int size);
void printArray(int array[],int size);

int main()
{
    int array[] = {9,1,8,2,7,3,6,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array,size);
    printArray(array,size);
    return 0;
}

void sort(int array[],int size)
{
    for (int i = 0; i < size - 1; i++)  //Initial num array index = i
    {
        for (int j = 0; j < size -i - 1; j++) // sort,until reach the bigger one
        {                                     // j < size -1 most basic
                                              // j < size -i -1   bubble sort
// In the nth round of sorting, the nth biggest num reaches its correct location
            if (array[j]>/*<:descending*/array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1]= temp;
            }
            
        }
        
    }
    
}

void printArray(int array[],int size)  //for loop print Array
{
    for (int i = 0; i < size; i++)  
    {
        printf("%d ",array[i]);
    }
    
}