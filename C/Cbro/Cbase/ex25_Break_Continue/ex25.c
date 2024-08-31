#include<stdio.h>

int main()
{
// continue = skip rest of code && forces the next iteration(迭代) of the loop 
// break = exits a loop/switch ; NOT the whole function
//(return :exits the function)

for (int i = 1; i <= 20 ; i++)
{
    if(i == 13)
    {
        //continue;
        break;
    }
    printf("%d\n",i);
}
    return 0;
}