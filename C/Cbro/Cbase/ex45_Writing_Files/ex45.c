#include<stdio.h>

int main()
{
    /*1*/
    /*FILE *pf = fopen("test.txt","w");    //type:file    name:pf
    //fopen(name,mode); w:rewrite; a:add; r:read
    fprintf(pf,"ADS");

    fclose(pf);*/
    
    /*2*/
    /*if(remove("test.txt") == 0)  //remove：delete the file
    {
        printf("Deleted!\n"); 
    }
    else
    {
        printf("Didn't execute deletion!\n");
    }
    */

    /*3*/

    FILE *pf = fopen("D:\\Computer_2Code\\VScode\\C\\Cbro\\Cbase\\ex45_Writing_Files\\test.txt","a");  //absolute path, use\\ instead of \ in this situation 
    
    fprintf(pf,"ADS\n");
    fclose(pf);

    return 0;
}