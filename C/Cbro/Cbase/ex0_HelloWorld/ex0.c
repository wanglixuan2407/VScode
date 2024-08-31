#include <stdio.h>
#include <string.h>
int main()
{
    printf("Hello,world!\n");
    printf("2024.7.11\n");
    printf("\0");//空字符串,而非空格符
    printf("strlen(\"\\0\") = %d",strlen("\0")); 
    return 0;
}