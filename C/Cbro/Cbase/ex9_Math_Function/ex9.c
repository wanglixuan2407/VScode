#include<stdio.h>
#include<math.h>  //math function <math.h>must be included
#define PI acos(-1) // PI
#define RAD_TO_DEG PI/180
int main()
{
    double A = sqrt(9);
    double B = pow(2,4); // 2^4 = 16  2 to the power of 4 is 16.
    int C = round(3.14); //3
    int D = ceil(3.14); //4
    int E = floor(3.99);  //3
    double F = fabs(-100); //jueduizhi
    double G = log(2.7828183); //log in C = ln  (e is the base)
    double H = sin(45*RAD_TO_DEG); //sin cos tan : rad
    double I = cos(60*RAD_TO_DEG); 
    double J = tan(45*RAD_TO_DEG);
    int K = abs(3);
    int L = abs(-3);

    printf("%-.2f\t,%-.2f\t,%d\n",A,B,C);
    printf("%d\t,%d\t,%-.2f\n,%-.2f\t,%-.2f\t,%-.2f\n,%-.2f\t",D,E,F,G,H,I,J);
    printf("PI=%.10f\n",PI);
    printf("abs(3)= %d, abs(-3)= %d",K,L);

    return 0;
}