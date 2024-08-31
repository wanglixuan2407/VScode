#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //memory = an array of bytes within RAM
    //memory block = a single unit(byte) within memory, used to hold some value
    //memory address = the address of where a memory block is located
    
    char a = 'X';
    //short b = 'Y';
    //int c = 'Z';
    //char s[3] = "Bro";
    char b = 'Y';
    char c = 'Z';
    char s = 'S'; 
    printf("%d Byte%s\n",sizeof(a),sizeof(a)>1?"s.":".");
    printf("%d Byte%s\n",sizeof(b),sizeof(b)>1?"s.":".");
    printf("%d Byte%s\n",sizeof(c),sizeof(c)>1?"s.":".");
    printf("%d Byte%s\n",sizeof(s),sizeof(s)>1?"s.":".");

    printf("%p\n",&a);  // Address %p in print , & to get the (start)address
    printf("%p\n",&b);  // Address written in HEX
    printf("%p\n",&c);  // Total: 16*16(HEX)=2^64 bytes(a memory block = 1 byte)
    printf("%p\n",&s);  // one address's size = 8bytes 

    return 0;
}