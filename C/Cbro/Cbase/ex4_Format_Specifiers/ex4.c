#include<stdio.h>
int main()
{
    //format specifiers   % = defines a type of data to be displayed
    //%c = character
    //%s = string (array of characters)
    //%f = float
    //%lf = double
    //%u = unsigned int 
    //%d = integer , short, unsigned short
    //%.1= decimal precision
    //%1 = minimum field width , if more than bytes a value contains, the left will be blank
    //%- = left align(zuoduiqi)
    float item1 = 5.75;
    float item2 = 10.00;
    float item3 = 100.99;

    printf("Item1:$%-8.2f\n",item1);
    printf("Item2:$%-8.2f\n",item2);
    printf("Item3:$%-8.2f\n",item3);
    printf("Comparison\n");
    printf("Item1:$%8.2f\n",item1);
    printf("Item2:$%8.2f\n",item2);
    printf("Item3:$%8.2f\n",item3);
    return 0;
}