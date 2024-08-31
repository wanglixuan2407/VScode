#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    double radius;
    double circumference;
    double area;
    double volumn;
    
    printf("Enter the radius:");
    scanf("%lf",&radius);

    circumference = 2 * PI * radius;
    area = PI * pow(radius,2);
    volumn = PI * 4.0/3.0 * pow(radius,3);

    printf("Circle's circumference = %.2f\n",circumference);
    printf("Circle's area = %.2f\n",area);
    printf("Ball's volumn = %.2f\n",volumn);
    return 0;
}