#include<stdio.h>

int main()
{
    char operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operator(+-*/): "); // % cannot be used between double
    scanf("%c",&operator);
    printf("\nPlease enter num1: ");
    scanf("%lf",&num1);
    printf("\nPlease enter num2: ");
    scanf("%lf",&num2);
    switch (operator)
    {
    case '+':
        result = num1 + num2 ;
        printf("\nresult:%lf",result);
        break;
    case '-':
        result = num1 - num2;
        printf("\nresult:%lf",result);
        break;
    case '*':
        result = num1*num2;
        printf("\nresult:%lf",result);
        break;
    case '/':
        if(num2 == 0){
            printf("\nError:Division is 0.0");
            break;
        }
        else{
        result = num1/num2;
        printf("\nresult:%lf",result);
        break;
        }
    default:
        printf("\nError:Invalid operator!");
        break;
    }
    return 0;
}