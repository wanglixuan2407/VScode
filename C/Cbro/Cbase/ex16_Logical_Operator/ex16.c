#include<stdio.h>
#include<stdbool.h>

int main()
{
    // && AND  || OR  ! NOT
    float temp = 25;
    bool sunny = false;
    bool cloudy = true;
    if((temp>=0)&&(temp<=30)&&sunny){
        printf("Good weather for trip!\n");
    }
    else{
        printf("Bad weather for trip!\n");
    }

    if(!cloudy){   //Pay Attention to this use: inside the if(),!logical 0=true; logical0=false
                   //use logical expression(e.g. == !=) in if()
                   /*DONOT use arithmatic expression in if()! Although the compiler will not report an error , it is a bad habit,which is bad for understanding.*/
        printf("NOT cloudy\n");
    }
    else{
        printf("Cloudy\n");
    }
    return 0;
}