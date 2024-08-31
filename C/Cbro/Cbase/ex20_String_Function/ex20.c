#include<stdio.h>
#include<string.h>  //string functions <string.h>

#define MAXINPUT 25

int main()
{
    char str1[]="Brother";
    char str2[]="crotde";
    char str3[MAXINPUT]="FGDSJDH";
    char str4[MAXINPUT];
    //strlwr(str1);           //convert a string to lowercase
    //strupr(str1);           //convert a string to uppercase
    //strcat(str1, str2);     //append str2 to end of str1
    //strncat(str1,str2,1);   //append n characters from str2 to str1
    //strcpy(str1,str2);      //copy str2 to str1 (delete str1)    
    //strncpy(str1,str2,3);   //copy n characters of str2 to str1  

    //strset(str1,'?');    //set all characters of a string to a given character
    //strnset(str1,'x',1); //set n characters of str1 to a given character
    //strrev(str1);          //reverse a string
    
    //printf("%s\n",str1);   //Operation object：str1(left)

    //int result = strlen(str1);       //return the string length as int
    //int result = strcmp(str1,str2);  //string compare all the characters
                                       //same:0 ; different:not 0(e.g.-1)
    //int result = strncmp(str1,str2,2); //string compare(from left)n characters
    //int result = strcmpi(str1,str2);    //string compare all(ignore u/l case)
    //int result = strnicmp(str1,str2);  
                    /*string compare(from left)n characters(ignore u/l case)*/
    
    //printf("%d",result);
    for (int i = 0; i < 10; i++)
    {
        fgets(str3,MAXINPUT,stdin);
    printf("%s,%d\n",str3,strlen(str3));  //strlen includes '\n'
    /*for (int i = 0; i < strlen(str3); i++) 
    {
        str3[i] = (i == 0)? str3[i]:'Z';
    }*/
    printf("%s",str3);
    printf("\nREMAIN:%d\n",strlen(str3));

    /*if strlen < MAXINPUT, the next fgets for a different string will not be influenced; BUT if you use fgets to a same string repeatedly,do not change the string after fgets,or there will be some strange problems. e.g. AZZZZZZ,the first letter is wrong.*/
    
    }
    
    fgets(str3,MAXINPUT,stdin);
    /*for (int j = 0; j < strlen(str3); j++)
    {
        str3[j] = (j == 0)? str4[j]:'Z';
    }*/         //This loop may cause FATAL ERROR in this code 24.7.19 17:50
    printf("%s",str3);
    printf("\nREMAIN:%d\n",strlen(str3));

    fgets(str4,MAXINPUT,stdin);
    /*for (int k = 0; k < strlen(str4); k++)
    {
        str4[k] = (k == 0)? str4[k]:'Z';
    }*/
    printf("%s",str4);
    printf("\nREMAIN:%d\n",strlen(str4));
    /* If user enter more than max numbers that fgets sets, the excess part will be cut in this string,but directly enter the next fgets and cause mistakes.*/ 
    
    return 0;
}