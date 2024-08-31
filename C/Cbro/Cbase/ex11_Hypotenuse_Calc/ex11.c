#include<stdio.h>
#include<math.h>

int main()
{
    double A;
    double B;
    double C;

    printf("Enter side A:");
    scanf("%lf",&A);
    printf("Side A is %.2lf\n",A);
    printf("Enter side B:");
    scanf("%lf",&B);
    printf("Side B is %.2lf\n",B);
    C = sqrt(A*A+B*B);
    printf("Hypotenuse C = %.2lf\n",C);
    printf("***************End***************\n");
    return 0;
}