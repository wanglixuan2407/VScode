#include<stdio.h>

int main()
{
    //arithmatic operators

    // + addition
    // - substraction
    // *multipulication
    // / division
    // % modulus
    // ++ increment  ++x:x=x+1,use the changed value ; x++:x=x+1,use the unchanged value
    // -- decrement

    // Pay attention to the data type and sequence!
    // ensure that there is at least 1 float or double in every calculation
    // e.g. float Temp, (Temp - 32.0) * 5.0 / 9.0 is safe.
    // (Temp - 32.0) * 9 / 5.0  is OK
    /* Temp * 4 / 3 is a little risky because the type depends on Temp(the created variable), 
    and the fault tolerance decreased. */
    /*Although the compiler can help us fix a lot of mistakes, we need to be aware of "consistent datatypes"!*/

    int x = 5;
    int y = 2;
    float a = 5;
    float b = 2;

    int z = x + y;
    int w = x - y;
    int f = x * y;
    float t = x / y; // If both x and y are integers , the result reserves the integer part.
                     // Otherwise, the result will be an accurate decimal.  
    float g = a / b;
    float h = x / b;
    float k = a / y;
    float n = x / (float)y; //(datatype):change the datatype  
    
    float s = x / y; // only reserve the integer part!
    
    int c = x % y;
    float r = x + a; 
    
/*At least 1 float +- any number of integers : Complier automatically changes result to float*/
    printf("%.2f\t",(float)4/3);// 1.33  sequence: ()> type change > */ > +-
    printf("%.2f\t",(float)(4/3));//1.00
    

    printf("%d,%d,%d,%.2f,%d\n",z,w,f,t,c); //7,3,10,2.00,1
    printf("%.2f,%.2f,%.2f,%.2f\n",g,h,k,n);//2.50 2.50 2.50 2.50
    printf("%.2f\n",s);//2.00
    printf("%d,%d,%d,%d,%d\n",x++,x++,++y,++x,++x); // 8,7,3,9,9 
    printf("%d,%d\n",x,y);  // 9 3

    /*Do not use ++ repeatedly on the same variable in printf*/
    /*In printf, x's final result is calculated , and then printed*/
}