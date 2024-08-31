#include<stdio.h>

int main()
{
    /*Variables"Allocate space in memory to store a value. 
      We refer to a variable's name to access the stored value.
      That valuable now behaves as if it was the value it contains.
      BUT we need to declare what type of data we're storing.  
    */
    int x;//declaration
    x = 123;//initialization
    int y = 321; //declaration+initialization

    int age = 21;//integer
    float gpa = 3.84; //floating point number;
    char grade ='B'; //char : single character , use ' ' 
    char name[] = "Bro"; //array of characters

    printf("You are %d years old\n",age); //%d-decimal-int age = 21
    printf("Hello,my name is %s\n",name); //%s-character string-char name[]="Bro"
    printf("Your average grade is %c\n",grade); //%c-single chracter-char grade = 'B'
    printf("Your gpa is %.2f\n",gpa); // %f-floating point number -float gpa = 3.84         
    return 0;
}