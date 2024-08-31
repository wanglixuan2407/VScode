#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //Bitwise operators =special operators used in bit level programming 
    //Knowing binary is important in this topic

    //  & = and ; | = or ; ^ = xor ; ~ = not
    //  << left shift   >> right shift

    int x = 6;   // int 4bytes  32bits  the last byte is:00000110
    int y = 12;  //                                      00001100
    int z = 0;   //                                      00000000

    z = x & y;
    printf("AND = %d\n",z); //4   00000100
    z = x | y;
    printf("OR = %d\n",z);  //14  00001110
    z = ~x;
    printf("NOT = %d\n",z); //-7  11111001   Complement Code 
    z = x ^ y;
    printf("XOR = %d\n",z); //10  00001010
    z = x << 1;
    printf("x<<1 = %d\n",z);//12  00001100
    z = x >> 1;
    printf("x>>1 = %d\n",z);//3   00000011
    return 0;
}