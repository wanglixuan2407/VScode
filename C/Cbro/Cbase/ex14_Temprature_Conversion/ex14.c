#include<stdio.h>
#include<ctype.h>
int main()
{
    char unit;
    double temp;
    printf("******************Welcome*****************\n");
    printf("Is the temperature in C or F ?");
    scanf("%c",&unit);
    unit = toupper(unit); // convert to capital letter  <ctype.h>
    switch (unit)
    {
    case 'C':
        printf("Please enter the temperature in Celcius:");
        scanf("%lf",&temp);
        temp = (temp * 9.0) / 5.0 + 32.0;
        printf("%.3lf in F\n",temp);
        break;
    case 'F':
    printf("Please enter the temperature in Farenheit:");
        scanf("%lf",&temp);
        temp = ((temp - 32.0) * 5.0) / 9.0; //HABIT:consistent datatype in calculation
        printf("%.3lf in Celcius\n",temp);
        break;
    default:
        printf("Invalid letter,please enter C or F!\n");
        break;
    }
    return 0 ;
    /*ex6: Although the compiler can help us fix a lot of mistakes, we need to be aware of "consistent datatypes"!*/
}