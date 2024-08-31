#include<stdio.h>
#include<string.h>

struct Student
{
    char name[12];
    float gpa;
};

int main()
{
    struct Student student1 = {"Spongbob",3.75};
    struct Student student2 = {"Patrick",3.60};
    struct Student student3 = {"Sandy",3.95};
    struct Student student4 = {"Squidward",3.83};

    struct Student students[] = {student1,student2,student3,student4};
    
    for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++)
    {
        printf("%-12s\t",students[i].name); //name space:12 + left justify
        printf("%-.2f\n",students[i].gpa);   
    }
    
    return 0;
}