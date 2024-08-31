#include<stdio.h>

int main()
{
    // Switch = A more efficient alternative to using many "else if " statements
    //          allows a value to be tested for equality against many cases

    char grade;
    printf("**************Welcome**************\n");
    printf("Enter a letter grade:");
    scanf("%c",&grade);

    switch (grade)
    {
        case 'A':
            printf("Perfect!\n");
            break;   //Each condition must be ended by a break!
        case 'B':
            printf("You did good!\n");
            break;
        case 'C':
            printf("You did OK!\n");
            break;
        case 'D':
            printf("At least it's not an F!\n");
            break;
        case 'F':
            printf("You failed!\n");
            break;
        default:
            printf("It 's not a normal grade!\n");
            break;
    }
    return 0;
}