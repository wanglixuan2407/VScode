#include<stdio.h>
#include<string.h>

void sort(char array[],int size);
void printArray(char array[],int size);

int main()
{
    char array[] = {'g','f','v','a','z','t','k'};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array,size);
    printArray(array,size);
    return 0;
}

void sort(char array[],int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (array[j]>array[j+1])  
            {
                char temp;
                temp = array[j]; 
                array[j] = array[j+1];
                array[j+1] = temp;
                /*As for numbers or single char,just use "=" to assign value
                because single character's second side is ASCII---%d.*/
            }
            
        }
        
    }
    

}
void printArray(char array[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c ",array[i]);
    }
    
}