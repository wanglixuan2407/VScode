#include<stdio.h>
#include<stdbool.h>

int main()
{
    char a = 'C'; // %c single character  
    char b[] = "Bro"; // %s array of characters   
    
    float c = 3.141592; // %f float : max accuracy : 8 bytes including '.' in total  
    double d = 313.141592653590; // %lfdouble : max accuracy :16 bytes including '.' in total  
    /*1 byte = 8 bits, float = 32 bits of precision;double = 64 bits of precision */
    /*You can change the bytes of integer and decimal and check the accuracy */
    bool e = true; // %d bool variation stores true and false;1byte(1=true,0=false) 
    /*before using bool, #include<stdbool.h>*/

    char f = 97; //%d or %c char---1byte(-128~127),ASCII(char as a numeric value)  
    char f1 = 'A';
    unsigned char g = 255;//%d or %c char---1byte(8bits,2^8=256), unsigned---0-255  

    short h = 32767;//%d 2bytes -32768~32767
    unsigned short i = 65535; //%d 2bytes 0~65535     2^16=65536

    int j = 2147483647;//%d 4bytes -2147483648~2147483647  (int = long int, long is neglected)
    unsigned int k = 4294967295;// %u 4bytes 0~4294967295    2^32=4294967296

    long long int l = 9223372036854775807 ;/*lld 8bytes                    -9223372036854775808~9223372036854775807*/
    unsigned long long int m = 18446744073709551615U;//llu 8bytes 0~18446744073709551616 (2^64)
    //To prevent the "too large "warning, add a 'U' at the end of unsigned long long int 
/*------------------------------------------------------------------------------------------*/
    printf("%.6f\n",c);  /*  %.6f:print 6 bits of decimal, regardless of the accuracy
                          if the value failed to meet the criteria above   */
    printf("%.12lf\n",d);// the same as above
    printf("%9.6f\n",c);
    /*Supplementary:
    If 9 > Total characters in c(including '.')(8), There will be blank on the left (9-8=1)
    Otherwise,it displays normally without blanks */
    printf("bool=%d\n",e);//bool
    printf("char f = %c,ASCII=%d\nchar f1 = %c,ASCII=%d",f,f,f1,f1);//char as an ACCII value
    printf("unsigned char g = %c,%d\n",g,g);
    
    printf("%d\n",h);
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%u\n",k);
    printf("%lld\n",l);
    printf("%llu\n",m);

    return 0;
}

/*Sum:
  Do pay attention to the data type in case that an overflow happens. e.g.0~255--256=0*/