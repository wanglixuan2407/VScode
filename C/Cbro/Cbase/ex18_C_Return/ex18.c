#include<stdio.h>

double square(double x);//declaration,the first double is the type of return value

int main()
{
    double data;
    double result;
    printf("Enter a data to square: ");
    scanf("%lf",&data);
    result = square(data);
    printf("The result is %lf",result);
    return 0;
}

double square(double x) //definition
{
    return x*x; 
}

//variable:double data in main()  ---double x in square
//  return:double result in main()---"double" before the function name
//x*x is double 