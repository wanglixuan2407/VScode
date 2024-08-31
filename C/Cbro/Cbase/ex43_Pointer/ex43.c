#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //pointer = a "variable-like" reference that holds a memory address to another variable,e.g. array,etc.
    //some takes are performed more easily with pointers 
    // declare a pointer: use * indirection operator(value at address)

    int age = 21;   
    //variable:lower case; pointer: *p + variable with 1st letter uppercase 
    int *pAge = &age;
    printf("address of age:%p\n",&age); //&age, pAge : int *
    printf("value of pAge:%p\n",pAge);  //age,*pAge : int  

    printf("size of age:%d bytes\n",sizeof(age)); //4 bytes (int)
    printf("size of pAge:%d bytes\n",sizeof(pAge));// 8 bytes (1 address)

    printf("value of age:%d\n",age);
    printf("value at stored address:%d\n",*pAge);  //dereferencing

    return 0;
}